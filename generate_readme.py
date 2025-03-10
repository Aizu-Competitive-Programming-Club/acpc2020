#!/usr/bin/env python3

import os
import json
import datetime
from datetime import timezone, timedelta, datetime
jst = timezone(timedelta(hours=+9), 'JST')

import sys
import subprocess
from pathlib import Path

base = "./"
target = "*"

import glob
import toml


def parse():
    tomls = list(
        filter(lambda p: not p.match('test/**/info.toml'),
               Path('.').glob('**/info.toml')))
    tomls = sorted(tomls, key=lambda x: x.parent.name)
    f_lis = tomls
    res = {}

    for file in f_lis:
        dict_toml = toml.load(open(str(file), "r"))
        if "title" not in dict_toml:
            continue
        p_name = dict_toml['title']
        if p_name != target and target != "*":
            continue
        if "solutions" not in dict_toml:
            continue
        res[p_name] = {}
        res[p_name]['TL'] = str(dict_toml["timelimit"])
        p_list = []
        for sol in dict_toml["solutions"]:
            p_list.append(sol)
        res[p_name]['SOL'] = p_list
        res[p_name]['directory'] = str(file)[:-9]

    return res


def git_push():
    url = 'https://{}:{}@github.com/{}.git'.format(os.environ['GITHUB_ACTOR'], os.environ['GITHUB_TOKEN'], os.environ['GITHUB_REPOSITORY'])

    subprocess.check_call(['git', 'config', '--global', 'user.name', 'GitHub'])
    subprocess.check_call(['git', 'config', '--global', 'user.email', 'noreply@github.com'])

    subprocess.check_call(['git', 'add', base + 'README.md'])

    if subprocess.run(['git', 'diff', '--quiet', '--staged']).returncode:
        message = '[generate_readme] update README.md'
        subprocess.check_call(['git', 'commit', '-m', message])
        subprocess.check_call(['git', 'push', url, 'HEAD'])

def target_select(branch):
    try:
        dict_toml = toml.load(open(base+'info.toml'))
        if branch in dict_toml:
            global target
            target = dict_toml[branch]
    except:
        pass

if __name__ == '__main__':
    branch = os.environ['GITHUB_REF'][len('refs/heads/'):]
    subprocess.check_call(['git', 'checkout', branch])
    target_select(branch)

    res = parse()
    readme_str_bef = ""
    readme_str_af = ""
    try:
        with open(base + "README.md") as f:
            mode = 0  # 0 before 1 inside 2 after

            for s_line in f:
                if s_line == "<!-- start " + target + " -->\n":
                    mode = 1
                    readme_str_bef += s_line
                elif s_line == "<!-- end " + target + " -->\n":
                    mode = 2
                    readme_str_af += s_line
                elif mode == 0:
                    readme_str_bef += s_line
                elif mode == 2:
                    readme_str_af += s_line
    except FileNotFoundError:
        readme_str_af = ""
    if readme_str_af == "":
        if target != "*":
            print("need run with target '*' for initialize readme.",
                  file=sys.stderr)
            sys.exit(1)
        readme_str_bef += "<!-- start * -->\n"
        readme_str_af += "<!-- end * -->\n"

    str_insert = ""
    for p_name, p_item in sorted(res.items(), key=lambda x: x[0]):
        d = p_item["directory"]
        str_base = ""
        if target == "*":
            str_base += "<!-- start " + p_name + " -->\n"

        str_base += "## [" + p_name + "]("+d+"/info.toml)\n"
        str_base += "### Time Limit: " + str(p_item["TL"]) + "\n"

        str_base += "| solution name | type |\n"
        str_base += "|----|----|\n"

        sol_l = p_item["SOL"]
        for sol in sol_l:
            if "name" not in sol:
                continue
            type = "AC"
            if "wrong" in sol:
                if sol["wrong"] == True:
                    type = "WA"
            if "allow_tle" in sol:
                if sol["allow_tle"] == True:
                    type = "TLE"

            str_base += "|[" + sol["name"] + "]("+d+"/sol/"+sol["name"]+")|" + type + "|\n"
        now = datetime.now(jst).strftime("%Y/%m/%d %H:%M:%S")
        str_base += "###### updated "+now+"\n"
        if target == "*":
            str_base += "<!-- end " + p_name + " -->\n"
        str_insert += str_base + "\n"
    res_readme = readme_str_bef + str_insert + readme_str_af

    with open(base + "README.md", mode='w') as f:
        f.write(res_readme)

    git_push()

#!/usr/bin/env python3

import os
import json
import datetime
import sys
import subprocess
from pathlib import Path

base = "./"
target ="*"

import glob
import toml
def parse():
    tomls = list(filter(lambda p: not p.match('test/**/info.toml'),
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
        p_list = [];
        for sol in dict_toml["solutions"]:
            p_list.append(sol)
        res[p_name]['SOL'] = p_list

    return res

def git_push():
    subprocess.run(("git","add",base+"README.md"))
    subprocess.run(("git","commit","-m","'update readme.md by generate_readme.py'"))
    subprocess.run(("git","push"))

if __name__ == '__main__':
    res = parse()
    readme_str_bef = ""
    readme_str_af = ""
    try:
        with open(base+"README.md") as f:
            mode = 0 # 0 before 1 inside 2 after

            for s_line in f:
                if s_line == "<!-- start "+target+" -->\n":
                    mode = 1
                    readme_str_bef+=s_line
                elif s_line == "<!-- end "+target+" -->\n":
                    mode = 2
                    readme_str_af += s_line
                elif mode == 0:
                    readme_str_bef+=s_line
                elif mode == 2:
                    readme_str_af += s_line
    except FileNotFoundError:
        readme_str_af = ""
    if readme_str_af =="":
        if target != "*":
            print("need run with target '*' for initialize readme.", file=sys.stderr)
            sys.exit(1)
        readme_str_bef+="<!-- start * -->\n"
        readme_str_af+="<!-- end * -->\n"

    str_insert =""
    for p_name, p_item in res.items():
        str_base=""
        str_base += "<!-- start "+p_name+"-->\n"

        str_base +="## "+p_name+"\n"
        str_base +="### Time Limit: "+str(p_item["TL"])+"\n"

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

            str_base += "|"+sol["name"]+"|"+type+"|\n"

        str_base += "<!-- end "+p_name +" -->\n"
        str_insert += str_base+"\n"
    res_readme=readme_str_bef+str_insert+readme_str_af

    with open(base+"README.md", mode = 'w') as f:
        f.write(res_readme)

    git_push()

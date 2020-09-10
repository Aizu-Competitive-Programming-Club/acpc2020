#!/usr/bin/env python3

import argparse
from sys import exit
import hashlib
import math
import re
import shutil
import subprocess
import tempfile
import zipfile
from datetime import datetime
from logging import Logger, basicConfig, getLogger
from os import environ, getenv, path
from pathlib import Path
from struct import pack
from subprocess import (DEVNULL, PIPE, STDOUT, CalledProcessError,
                        TimeoutExpired, call, check_call, check_output, run)
from tempfile import TemporaryDirectory

import markdown.extensions
from jinja2 import Template, Environment, DictLoader
import toml
from markdown import Extension, markdown
from markdown.preprocessors import Preprocessor

from generate import Problem
from typing import Set

logger = getLogger(__name__)  # type: Logger


# html tag for change lang
def lang_div_start(lang):
    return '<div markdown="1" class="lang-{}">'.format(lang)


def lang_div_end(lang):
    return '</div>'


# @{keyword.statement}, @{keyword.constraints}, ...
def to_keyword_str(lang_dict):
    s = ''
    for k, v in lang_dict.items():
        s += lang_div_start(k) + v + lang_div_end(k)
    return s


keywords = {
    'statement': to_keyword_str({
        'en': 'Problem Statement',
    }),
    'constraints': to_keyword_str({
        'en': 'Constraints',
    }),
    'input': to_keyword_str({
        'en': 'Input',
    }),
    'output': to_keyword_str({
        'en': 'Output',
    }),
    'sample': to_keyword_str({
        'en': 'Sample',
    }),
}


def param_to_str(value):
    if isinstance(value, int):
        if str(value).endswith('000000'):
            k = math.floor(math.log10(abs(value)))
            if value == 10 ** k:
                return r'10^{{{}}}'.format(k)
            elif value % (10 ** k) == 0:
                return r'{} \\times 10^{{{}}}'.format(value // 10 ** k, k)
            else:
                return r'{} \\times 10^{{{}}}'.format(value / 10 ** k, k)
        else:
            return format(value, ',').replace(',', '{,}')
    else:
        return str(value)


def gen_params(toml_params):
    params = dict()  # type: Dict[str, str]
    for key, value in toml_params.items():
        params[key] = param_to_str(value)
    return params


# @{example.example_00}
class ExampleReader:
    sample_template = '''
<div class="uk-grid-small uk-child-width-1-2@s" uk-grid>
    <h2>Sample Input {}</h2><pre>{}</pre>
    <h2>Sample Output {}</h2><pre>{}</pre>
</div>
'''

    def __init__(self, problem_dir: Path):
        self.counter = 0
        self.problem_dir = problem_dir
        self.used = set()  # type: Set[str]

    def __getitem__(self, key: str):
        logger.debug('read example: {}'.format(key))
        self.used.add(key)
        inpath = self.problem_dir / 'in' / (key + '.in') # type: Path
        outpath = self.problem_dir / 'out' / (key + '.out') # type: Path
        if not inpath.exists() or not outpath.exists():
            logger.error('There is no example file {}'.format(key))
            exit(1)
        infile = open(str(inpath), 'r').read()
        outfile = open(str(outpath), 'r').read()

        self.counter += 1
        return self.sample_template.format(self.counter, infile,
                                           self.counter, outfile)

    def check_all_used(self) -> bool:
        for file_path in Path(self.problem_dir).glob('in/example_*.in'):
            name = file_path.stem
            if name not in self.used:
                logger.warn('Not use {} for task.md'.format(name))
                return False
        return True


class LangManager:
    def __init__(self):
        self.now_lang = ''

    def __getitem__(self, lang: str):
        if lang == 'end':
            return self.reset_lang()
        s = ''
        if self.now_lang != '':
            s += self.reset_lang()
        self.now_lang = lang
        return s + lang_div_start(lang)

    def reset_lang(self):
        s = lang_div_end(self.now_lang)
        self.now_lang = ''
        return s

html_header = '''
'''
html_body = '''
{}
'''


class ToHTMLConverter:
    def __init__(self, probdir: Path, config):
        logger.info("HTML Generate {}".format(probdir.name))
        md_statement = open(str(probdir / 'task.md'), encoding='utf-8').read()
        md_statement = md_statement.replace('```\n', '<pre>', 1)
        md_statement = md_statement.replace('\n```', '</pre>', 1)
        # evaluate jinja2
        lang_manager = LangManager()
        environment = Environment(
            variable_start_string="@{", variable_end_string="}", loader=DictLoader({'task': md_statement}))
        environment.globals['endlang'] = lang_manager.reset_lang
        template = environment.get_template('task')
        self.examples = ExampleReader(problem_dir=probdir)
        mid_statement = template.render(
            keyword=keywords,
            param=gen_params(config.get('params', dict())),
            lang=lang_manager,
            example=self.examples,
        )

        # evaluate markdown
        self.statement = markdown(
            mid_statement, extensions=[
                'md_in_html',
                'markdown.extensions.fenced_code',
            ],
        )
        self.html = html_header + html_body.format(self.statement)

    def check_all_samples_used(self) -> bool:
        return self.examples.check_all_used()

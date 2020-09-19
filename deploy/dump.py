#!/usr/bin/env python3

import os
import sys
import json

assert(os.path.basename(os.getcwd()) == 'deploy')

assert(len(sys.argv) >= 3)
start = int(sys.argv[1])
num = int(sys.argv[2])

problems = []
for i in range(num):
    problem = {}
    problem['id'] = str(start + i)
    print(problem['id'])
    with open('../pack/html/' + problem['id'] + '.html') as f:
        problem['statement'] = f.read()
    problems.append(problem)

with open('../pack/problems.json', 'w') as f:
    json.dump(problems, f)

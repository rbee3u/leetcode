# -*- coding:utf-8 -*-
import json
import os
from urllib.parse import quote
from pipe import *

# 语言及其对应子目录名称
language_subs = [
    ('C', ['c']),
    ('C++', ['cpp', 'cc', 'cplusplus']),
    ('Elixir', ['elixir', 'ex']),
    ('Erlang', ['erlang', 'erl']),
    ('Go', ['golang', 'go']),
    ('Java', ['java']),
    ('JS', ['javascript', 'js']),
    ('Python', ['python', 'py']),
    ('Rust', ['rust', 'rs']),
    ('SQL', ['sql']),
    ('Shell', ['shell']),
]


# 获取问题对应的语言列表
def get_languages(problem):
    directories = os.listdir(problem)
    languages = []
    for (language, subs) in language_subs:
        if len(set(subs) & set(directories)):
            languages.append(language)
    return '/'.join(languages)


# 获取问题对应的整行数据
def get_row(problem):
    basename = os.path.basename(problem)
    attr = json.load(open(os.path.join(problem, 'attr.json')))
    number = '%04d' % int(attr.get('id', '0'))
    title = '[%s]( %s )' % (attr.get('title', ''), attr.get('url', ''))
    solution = '[%s]( src/%s )' % (get_languages(problem), quote(basename))
    # favorite: ⭐
    # complete: ✅
    addition = attr.get('addition', '')
    return number, title, addition, solution


# 格式化整行数据
def fmt_row(row):
    return '| %s | %s %s | %s |' % row


if __name__ == '__main__':
    (__file__
     | Pipe(os.path.realpath)
     | Pipe(os.path.dirname)
     | Pipe(os.chdir)
     )
    outfile = open('README.md', 'w')
    outfile.write('# LeetCode Solutions\n\n')
    outfile.write('| Index | Title | Solution |\n')
    outfile.write('| :---: | :---- | :------: |\n')
    (os.listdir('src')
     | select(lambda p: os.path.join('src', p))
     | where(os.path.isdir)
     | select(get_row)
     | sort
     | select(fmt_row)
     | Pipe('\n'.join)
     | Pipe(outfile.write)
     | Pipe(lambda _: print('Done!'))
     )

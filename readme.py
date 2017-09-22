# -*- coding:utf-8 -*-
import json
import os
from urllib.parse import quote

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
    os.chdir(os.path.dirname(os.path.realpath(__file__)))

    outfile = open('README.md', 'w')
    outfile.write('# LeetCode Solutions\n\n')
    outfile.write('| Index | Title | Solution |\n')
    outfile.write('| :---: | :---- | :------: |\n')

    subs = [os.path.join('src', p) for p in os.listdir('src')]
    rows = sorted([get_row(sub) for sub in subs])
    outfile.write('\n'.join([fmt_row(row) for row in rows]))

    print('Done!')

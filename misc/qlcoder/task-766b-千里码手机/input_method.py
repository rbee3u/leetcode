# -*- coding: utf-8 -*-
import itertools

kb_mp = {}
kb_mp['1'] = [' ','.','!']
kb_mp['2'] = ['q','b','x']
kb_mp['3'] = ['z','u','v']
kb_mp['4'] = ['g','h','j']
kb_mp['5'] = ['m','p','l']
kb_mp['6'] = ['f','c','y','t']
kb_mp['7'] = ['k','n','r']
kb_mp['8'] = ['a','e','w']
kb_mp['9'] = ['i','d','o','s']

def all_combinations(digits):
	args = tuple([kb_mp[d] for d in digits])
	products = itertools.product(*args)
	return [''.join(list(tp)) for tp in products]

instr = '648159969691164817828591164816793258587879116481793791584919716481923878149589116481978918491988164974919966878765611648618781796169791961735891187916486148381791789586616971648196863912391169316871239681648511999847881896416485114597966197139596616485118293616481975616497416931687179619919919479781648511286839816486164874816497491164861539416481435871786816978879118791849581995815861988164851891648167836197891188198814879391128683981648158955818491878167836187934416916497716486168716487481648189759187816481978918491991'
inlst = [x for x in instr.split('1') if 0 < len(x) and len(x) < 20]

words = set([s.lower()[:-2:1] for s in open('linuxwords.txt', 'r').readlines()])

for digits in inlst:
	print(digits, end=': ')
	for x in all_combinations(digits):
		if x in words:
			print(x, end=' ')
	print('')


# -*- coding: utf-8 -*-
from __future__ import division

def myord(x):
	if x.isdigit():
		return int(x)
	else:
		return ord(x)-97

def myord2(n1, n2):
	return n1*26 + n2;

freqs = [[0]*26 for i in range(10)]
for line in open('145835459995807.txt', 'r'):
	tokens = line.split(',')
	alpha = myord(tokens[0])
	digit = myord(tokens[1])
	count = int(tokens[2])
	freqs[digit][alpha] += count

for digit in range(10):
	total = sum(freqs[digit])
	if total == 0: continue
	for alpha in range(26):
		freqs[digit][alpha] /= total

print('freqs done!')

trans = [0] * (26*26)
for line in open('145835462696852.txt', 'r'):
	idx, line_size = 1, len(line)
	while idx < line_size:
		n1 = myord(line[idx-1])
		n2 = myord(line[ idx ])
		trans[myord2(n1, n2)] += 1
		idx += 1

print('trans done!')

instr = '635753548643866452536623'
outstr = ''

def find_two(d1, d2):
	max_prob, max_c1, max_c2 = 0, 0, 0
	for c1 in range(26):
		for c2 in range(26):
			prob = freqs[d1][c1]*freqs[d2][c2] \
						* trans[myord2(c1, c2)]
			if max_prob < prob:
				max_prob, max_c1, max_c2 = prob, c1, c2
	return (max_c1, max_c2)

(first, second) = find_two(myord(instr[0]), myord(instr[1]))
outstr += chr(first + 97)
outstr += chr(second + 97)

print(outstr)

def find_one(p, d):
	max_prob, max_c = 0, 0
	for c in range(26):
		prob = freqs[d][c]*trans[myord2(p, c)]
		if max_prob < prob:
			max_prob, max_c = prob, c
	return max_c

prev = second
for d in instr[2:]:
	prev = find_one(prev, myord(d))
	outstr += chr(prev + 97)
	print(outstr)

print(outstr)

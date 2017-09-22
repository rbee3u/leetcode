# -*- coding: utf-8 -*-
import json
import copy

jstr = open('in.json', 'r').read()
jobj = json.loads(jstr)

fout = open('in.data', 'w')

fout.write(str(len(jobj.get('pieces'))//2)+'\n')
level = jobj.get('level', 0)
fout.write(str(level)+'\n')
# fout.write('\n')

modu  = jobj.get('modu',  2)
fout.write(modu+'\n')
# fout.write('\n')

grid = jobj.get('map')
grid_n = len(grid)
grid_m = len(grid[0])
fout.write(str(grid_n)+' ')
fout.write(str(grid_m)+'\n')
ones = ''
twos = ''
for row in grid:
	for x in row:
		if x == '0':
			ones = '0' + ones
			twos = '0' + twos
		elif x == '1':
			ones = '1' + ones
			twos = '0' + twos
		elif x == '2':
			ones = '0' + ones
			twos = '1' + twos
		else:
			ones = '1' + ones
			twos = '1' + twos
fout.write(str(int(ones, 2)) + ' ')
fout.write(str(int(twos, 2)) + '\n')

pieces = jobj.get('pieces')
price_n = len(pieces)
fout.write(str(price_n)+'\n')
# fout.write('\n')
pid = 0
for piece in pieces:
	tokens = piece.split(',')
	row_p = len(tokens)
	col_p = len(tokens[0])
	bits = [''] * grid_n
	for row in range(grid_n):
		for col in range(grid_m):
			if row < row_p and col < col_p:
				if tokens[row][col] == 'X':
					bits[row] += '1'
				else:
					bits[row] += '0'
			else:
				bits[row] += '0'
	total = (grid_n-row_p+1)*(grid_m-col_p+1)
	pid = pid + 1
	fout.write(str(total)+'\n')
	for sft_row in range(grid_n-row_p+1):
		for sft_col in range(grid_m-col_p+1):
			fout.write(str(pid)+' ')
			dits = copy.deepcopy(bits)
			# print(dits)
			for row in range(grid_n):
				dits[row] = dits[row][-sft_col:] + dits[row][:-sft_col]
			dits = dits[-sft_row:] + dits[:-sft_row]
			# print('\n'.join(dits)+'\n')
			fout.write(str(sft_row)+' '+str(sft_col)+' ')
			# print(''.join(dits)[::-1])
			# print(int(''.join(dits)[::-1], 2))
			fout.write(str(int(''.join(dits)[::-1], 2))+'\n')


import math
ans_row, ans_val = 0, 0
tmp_row = 0
for line in open('p099_base_exp.txt').readlines():
	tmp_row += 1
	(base, expi) = tuple(map(int, line.split(',')))
	tmp_val = expi * math.log(base)
	if tmp_val > ans_val:
		ans_row = tmp_row
		ans_val = tmp_val

print(ans_row)


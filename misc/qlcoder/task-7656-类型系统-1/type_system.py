# -*- coding: utf-8 -*-
import re

typeset = set([])
vardict = {}

for line in open('145743685778441.txt', 'r'):
	tokens = re.split(r'\s+', line)
	if tokens[0] == 'type':
		atype = tokens[1]
		if atype not in typeset:
			typeset.add(atype)
	elif tokens[1] == ':=':
		avar = tokens[0]
		if avar not in vardict:
			if tokens[2] == 'new':
				atype = tokens[3]
				if atype in typeset:
					vardict[avar] = atype
				else:
					pass
			else:
				avar2 = tokens[2]
				if avar2 in vardict:
					vardict[avar] = vardict[avar2]
				else:
					pass
	else:
		pass

varlist = sorted(list(vardict.items()))
for (avar, atype) in varlist:
	print('%s-%s' % (avar, atype), end='-')



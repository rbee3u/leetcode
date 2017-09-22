t1 = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
t2 = ['ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
t3 = ['twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']

n1 = sum(map(lambda x: len(x)*9*10, t1))
n2 = sum(map(lambda x: len(x)*10, t2))
n3 = sum(map(lambda x: len(x)*10*10, t3))
n4 = len('hundred') * 900
n5 = len('and') * (900 - 9)
n6 = sum(map(lambda x: len(x)*100, t1))
n7 = len('onethousand')

print(n1 + n2 + n3 + n4 + n5 + n6 + n7)



func numberOfSteps(num int) (res int) {
	for res = num & 1; num > 1; {
		num >>= 1
		res += 1 + num&1
	}
	return res
}

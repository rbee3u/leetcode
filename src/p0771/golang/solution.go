func numJewelsInStones(J string, S string) (result int) {
	dict := make(map[int32]int)
	for _, k := range J {
		dict[k] = 1
	}
	for _, k := range S {
		result += dict[k]
	}
	return result
}

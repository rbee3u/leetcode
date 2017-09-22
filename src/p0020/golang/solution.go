func isValid(s string) bool {
	var stk []byte
	for i := 0; i < len(s); i++ {
		if len(stk) == 0 {
			stk = append(stk, s[i])
		} else {
			if isMatch(stk[len(stk)-1], s[i]) {
				stk = stk[:len(stk)-1]
			} else {
				stk = append(stk, s[i])
			}
		}
	}
	return len(stk) == 0
}

func isMatch(p byte, q byte) bool {
	return p == '(' && q == ')' ||
		p == '[' && q == ']' ||
		p == '{' && q == '}'
}

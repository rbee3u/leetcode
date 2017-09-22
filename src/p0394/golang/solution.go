package main

func main() {
	decodeString("3[a]2[bc]")
}

func decodeString(s string) (ans string) {
	plain, _ := consumeS([]byte(s))
	return string(plain)
}

// S := AS | N[S]S | e
// A := aA | a
// N := nN | n
func consumeS(cipher []byte) (plain []byte, rest []byte) {
	for rest = cipher; len(rest) > 0; {
		if isAlpha(rest[0]) {
			a, r := consumeA(rest)
			plain = append(plain, a...)
			rest = r
		} else if isDigit(rest[0]) {
			n, t := consumeN(rest)
			t = t[1:] // [
			s, r := consumeS(t)
			r = r[1:] // ]
			for i := 0; i < n; i++ {
				plain = append(plain, s...)
			}
			rest = r
		} else {
			break
		}
	}
	return plain, rest
}

func consumeA(cipher []byte) (plain []byte, rest []byte) {
	for rest = cipher; len(rest) > 0; rest = rest[1:] {
		if !isAlpha(rest[0]) {
			break
		}
		plain = append(plain, rest[0])
	}
	return plain, rest
}

func consumeN(cipher []byte) (plain int, rest []byte) {
	for rest = cipher; len(rest) > 0; rest = rest[1:] {
		if !isDigit(rest[0]) {
			break
		}
		plain = plain*10 + int(rest[0]-'0')
	}
	return plain, rest
}

func isOpen(c byte) bool {
	return c == '['
}

func isClose(c byte) bool {
	return c == ']'
}

func isDigit(c byte) bool {
	return '0' <= c && c <= '9'
}

func isAlpha(c byte) bool {
	return !isOpen(c) && !isClose(c) && !isDigit(c)
}

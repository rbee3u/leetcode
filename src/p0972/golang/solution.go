package main

func main() {
	isRationalEqual("1", "0.99(99)")
}

func isRationalEqual(S string, T string) bool {
	ns, ds := parse(S)
	nt, dt := parse(T)
	return ns*dt == ds*nt
}

func parse(s string) (n, d int64) {
	var n1, d1, n2, d2 int64
	for _, c := range s {
		switch {
		case c == '.':
			d1 = 1
		case c == '(':
			d2 = 1
		case c == ')':
		case d2 > 0:
			n2 = n2*10 + (int64(c) - '0')
			d2 = d2 * 10
		case d1 > 0:
			n1 = n1*10 + (int64(c) - '0')
			d1 = d1 * 10
		default:
			n1 = n1*10 + (int64(c) - '0')
		}
	}
	if d1 < 1 {
		d1 = 1
	}
	if d2 < 10 {
		n, d = n1, d1
	} else {
		n, d = n1*(d2-1)+n2, d1*(d2-1)
	}
	return n, d
}

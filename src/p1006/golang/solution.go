package main

func clumsy(n int) int {
	result, sign := 0, 1
	for n > 0 {
		temp := n
		n--
		if n > 0 {
			temp *= n
			n--
		}
		if n > 0 {
			temp /= n
			n--
		}
		temp *= sign
		if n > 0 {
			temp += n
			n--
		}
		result += temp
		sign = -1
	}
	return result
}

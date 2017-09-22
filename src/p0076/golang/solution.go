package main

func main() {
	minWindow("ADOBECODEBANC", "ABC")
}

func minWindow(s string, t string) (result string) {
	exist := make(map[byte]struct{})
	dict := make(map[byte]int)
	for i := 0; i < len(t); i++ {
		exist[t[i]] = struct{}{}
		dict[t[i]] = dict[t[i]] - 1
	}
	negative := len(dict)
	left, right := 0, -1
	for {
		right++
		if right >= len(s) {
			break
		}
		if _, ok := exist[s[right]]; !ok {
			continue
		}
		dict[s[right]] = dict[s[right]] + 1
		if dict[s[right]] == 0 {
			delete(dict, s[right])
			negative--
		}
		if negative == 0 {
			for {
				if left > right {
					break
				}
				if _, ok := exist[s[left]]; !ok {
					left++
					continue
				}
				if dict[s[left]] > 0 {
					dict[s[left]] = dict[s[left]] - 1
					left++
					continue
				}
				break
			}
			if result == "" || len(result) > right-left+1 {
				result = s[left:right+1]
			}
		}
	}
	return result
}

package main

func findAnagrams(s string, p string) (ans []int) {
	dict := make(map[byte]int)
	for i := 0; i < len(p); i++ {
		dict[p[i]] = dict[p[i]] - 1
	}
	n := len(p)
	for i := 0; i < len(s); i++ {
		if i >= n {
			dict[s[i-n]] = dict[s[i-n]] - 1
			if dict[s[i-n]] == 0 {
				delete(dict, s[i-n])
			}
		}
		dict[s[i]] = dict[s[i]] + 1
		if dict[s[i]] == 0 {
			delete(dict, s[i])
		}
		if len(dict) == 0 {
			ans = append(ans, i-n+1)
		}
	}
	return ans
}

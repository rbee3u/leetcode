package main

import (
	"fmt"
)

func commonChars(strs []string) (result []string) {
	var curr, next [26]int
	for i := 0; i < len(strs); i++ {
		for j := 0; j < len(strs[i]); j++ {
			c := strs[i][j]
			if i == 0 || curr[c - 'a'] > 0 {
				curr[c - 'a']--
				next[c - 'a']++
			}
		}
		for k := 0; k < 26; k++ {
			curr[k], next[k] = next[k], 0
		}
	}
	for i, v := range curr {
		for ; v > 0; v-- {
			result = append(result, fmt.Sprintf("%c", i + 'a'))
		}
	}
	return result
}

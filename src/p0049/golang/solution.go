package main

import (
	"sort"
)

func groupAnagrams(strs []string) (ans [][]string) {
	dict := make(map[string][]string)
	for _, str := range strs {
		key := sorted(str)
		dict[key] = append(dict[key], str)
	}
	for _, value := range dict {
		ans = append(ans, value)
	}
	return ans
}

func sorted(str string) string {
	bts := []byte(str)
	sort.Slice(bts, func(i int, j int) bool {
		return bts[i] < bts[j]
	})
	return string(bts)
}
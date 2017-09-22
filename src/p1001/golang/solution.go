package main

import (
	"fmt"
)

func gridIllumination(N int, lamps [][]int, queries [][]int) (result []int) {
	sources := make(map[int]map[int]struct{})
	row := make(map[int]int)
	col := make(map[int]int)
	add := make(map[int]int)
	sub := make(map[int]int)
	for _, lamp := range lamps {
		x, y := lamp[0], lamp[1]
		if _, ok := sources[x]; !ok {
			sources[x] = make(map[int]struct{})
		}
		sources[x][y] = struct{}{}
		row[x]++
		col[y]++
		add[x + y]++
		sub[x - y]++
	}
	for _, query := range queries {
		i, j := query[0], query[1]
		if row[i] > 0 || col[j] > 0 || add[i + j] > 0 || sub[i - j] > 0 {
			result = append(result, 1)
		} else {
			result = append(result, 0)
		}
		for x := i - 1; x <= i + 1; x++ {
			for y := j - 1; y <= j + 1; y++ {
				if _, okx := sources[x]; okx {
					if _, oky := sources[x][y]; oky {
						delete(sources[x], y)
						row[x]--
						col[y]--
						add[x + y]--
						sub[x - y]--
					}
				}
			}
		}
	}
	return result
}

func main() {
	dict := make(map[int]int)
	dict[2]++
	fmt.Println(dict[2])
}
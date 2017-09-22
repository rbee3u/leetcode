package main

import (
	"sort"
)

func reconstructQueue(peoples [][]int) (queue [][]int) {
	sort.Slice(peoples, func(i int, j int) bool {
		if peoples[i][0] == peoples[j][0] {
			return peoples[i][1] < peoples[j][1]
		}
		return peoples[i][0] > peoples[j][0]
	})
	for _, people := range peoples {
		i := people[1]
		queue = append(queue, nil)
		copy(queue[i+1:], queue[i:])
		queue[i] = people
	}
	return queue
}


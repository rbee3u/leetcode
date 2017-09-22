package main

import (
	"sort"
)

type Interval struct {
	Start int
	End   int
}

func merge(intervals []Interval) (ans []Interval) {
	sort.Slice(intervals, func(i int, j int) bool {
		if intervals[i].Start == intervals[j].Start {
			return intervals[i].End > intervals[j].End
		}
		return intervals[i].Start < intervals[j].Start
	})
	n := len(intervals)
	for i := 0; i < n; {
		j := i + 1
		for ; j < n; j++ {
			if intervals[i].End < intervals[j].Start {
				break
			}
			if intervals[i].End < intervals[j].End {
				intervals[i].End = intervals[j].End
			}
		}
		ans = append(ans, intervals[i])
		i = j
	}
	return ans
}

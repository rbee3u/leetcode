package main

func numPairsDivisibleBy60(times []int) (result int) {
	var counts [60]int
	for _, time := range times {
		time %= 60
		result += counts[(60 - time) % 60]
		counts[time]++
	}
	return result
}

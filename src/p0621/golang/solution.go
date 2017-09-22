package main

func leastInterval(tasks []byte, n int) int {
	counts := make(map[byte]int)
	for _, task := range tasks {
		counts[task] = counts[task] + 1
	}
	maxCount, maxCountNum := 0, 1
	for _, count := range counts {
		if maxCount < count {
			maxCount, maxCountNum = count, 1
		} else if maxCount == count {
			maxCountNum++
		}
	}
	// fmt.Printf("maxCount: %d, maxCountNum: %d\n", maxCount, maxCountNum)
	colNum := maxCount - 1
	rowNum := n - (maxCountNum - 1)
	// fmt.Printf("colNum: %d, rowNum: %d\n", colNum, rowNum)
	if rowNum < 0 {
		rowNum = 0
	}
	idleNum := colNum * rowNum - (len(tasks) - maxCount * maxCountNum)
	if idleNum < 0 {
		idleNum = 0
	}
	return len(tasks) + idleNum
}

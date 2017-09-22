package main

func longestConsecutive(nums []int) (ans int) {
	visit := make(map[int]bool)
	for _, num := range nums {
		visit[num] = false
	}
	for _, num := range nums {
		visited, ok := visit[num]
		if !ok || visited {
			continue
		}
		tmp := 1
		for large := num + 1; ; large++ {
			visited, ok = visit[large]
			if !ok || visited {
				break
			}
			tmp++
			visit[large] = true
		}
		for small := num - 1; ; small-- {
			visited, ok = visit[small]
			if !ok || visited {
				break
			}
			tmp++
			visit[small] = true
		}
		if ans < tmp {
			ans = tmp
		}
	}
	return ans
}


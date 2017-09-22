package main

type MinHeap struct {
	array []int
	size  int
}

func (h *MinHeap) MinHeapify(i int) {
	l, r := i*2, i*2+1
	j := i
	if r <= h.size && h.array[j] > h.array[r] {
		j = r
	}
	if l <= h.size && h.array[j] > h.array[l] {
		j = l
	}
	if j != i {
		h.array[i], h.array[j] = h.array[j], h.array[i]
		h.MinHeapify(j)
	}
}

func (h *MinHeap) Minimum() int {
	return h.array[1]
}

func (h *MinHeap) Build() {
	for i := h.size/2; i >= 1; i-- {
		h.MinHeapify(i)
	}
}

func (h *MinHeap) Insert(x int) {
	if x <= h.array[1] {
		return
	}
	h.array[1] = x
	h.MinHeapify(1)
}

func findKthLargest(nums []int, k int) int {
	h := &MinHeap{
		array: make([]int, k+1),
		size:  k,
	}
	for i := 0; i < k; i++ {
		h.array[i+1] = nums[i]
	}
	h.Build()
	for i := k; i < len(nums); i++ {
		h.Insert(nums[i])
	}
	return h.Minimum()
}

func main() {
	findKthLargest([]int{3,2,1,5,6,4}, 2)
}
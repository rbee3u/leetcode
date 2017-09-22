package main

func hammingDistance(x int, y int) (d int) {
	for z := x ^ y; z != 0; z ^= z & (-z) {
		d++
	}
	return d
}
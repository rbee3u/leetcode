package main

func powerfulIntegers(x int, y int, bound int) (ans []int) {
	pxs, pys := powers(x, bound), powers(y, bound)
	dict := make(map[int]struct{})
	for _, px := range pxs {
		for _, py := range pys {
			if px + py <= bound {
				dict[px+py] = struct{}{}
			}
		}
	}
	for k := range dict {
		ans = append(ans, k)
	}
	return ans
}

func powers(z int, bound int) (pzs []int) {
	pz := 1
	pzs = append(pzs, pz)
	if z <= 1 {
		return pzs
	}
	for pz <= bound {
		pz = pz * z
		pzs = append(pzs, pz)
	}
	return pzs
}

func defangIPaddr(address string) string {
	var result []byte
	for i := 0; i < len(address); i++ {
		if address[i] == '.' {
			result = append(result, '[', '.', ']')
		} else {
			result = append(result, address[i])
		}
	}
	return string(result)
}

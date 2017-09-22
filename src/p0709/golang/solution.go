func toLowerCase(str string) string {
	var chars []byte
	for _, char := range []byte(str) {
		if char >= 'A' && char <= 'Z' {
			char = char + 'a' - 'A'
		}
		chars = append(chars, char)
	}
	return string(chars)
}

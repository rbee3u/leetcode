package main

import (
	"unicode"
)

func isNumber(s string) bool {
	curr := 1
	for _, c := range s {
		switch curr {
		case 1:
			if isblank(c) {
				curr = 1
				continue
			}
			if issign(c) {
				curr = 2
				continue
			}
			if isdigit(c) {
				curr = 3
				continue
			}
			if isdot(c) {
				curr = 4
				continue
			}
			return false
		case 2:
			if isdigit(c) {
				curr = 3
				continue
			}
			if isdot(c) {
				curr = 4
				continue
			}
			return false
		case 3:
			if isdigit(c) {
				curr = 3
				continue
			}
			if isdot(c) {
				curr = 5
				continue
			}
			if isexp(c) {
				curr = 6
				continue
			}
			if isblank(c) {
				curr = 9
				continue
			}
			return false
		case 4:
			if isdigit(c) {
				curr = 5
				continue
			}
			return false
		case 5:
			if isdigit(c) {
				curr = 5
				continue
			}
			if isexp(c) {
				curr = 6
				continue
			}
			if isblank(c) {
				curr = 9
				continue
			}
			return false
		case 6:
			if issign(c) {
				curr = 7
				continue
			}
			if isdigit(c) {
				curr = 8
				continue
			}
			return false
		case 7:
			if isdigit(c) {
				curr = 8
				continue
			}
			return false
		case 8:
			if isdigit(c) {
				curr = 8
				continue
			}
			if isblank(c) {
				curr = 9
				continue
			}
			return false
		case 9:
			if isblank(c) {
				curr = 9
				continue
			}
			return false
		}
	}
	return curr == 3 || curr == 5 || curr == 8 || curr == 9;
}

func isblank(c rune) bool {
	return unicode.IsSpace(c)
}

func isdigit(c rune) bool {
	return unicode.IsDigit(c)
}

func issign(c rune) bool {
	return c == '+' || c == '-'
}

func isdot(c rune) bool {
	return c == '.'
}

func isexp(c rune) bool {
	return c == 'e'
}

package main

import (
	"strings"
)

func spellchecker(wordlist []string, queries []string) (ans []string) {
	wordsDict := make(map[string][]string)
	casesDict := make(map[string][]string)
	vowelDict := make(map[string][]string)
	for _, word := range wordlist {
		wordsWord := toWordsWord(word)
		wordsDict[wordsWord] = append(wordsDict[wordsWord], word)
		casesWord := toCasesWord(word)
		casesDict[casesWord] = append(casesDict[casesWord], word)
		vowelWord := toVowelWord(word)
		vowelDict[vowelWord] = append(vowelDict[vowelWord], word)
	}
	for _, query := range queries {
		if values, ok := wordsDict[toWordsWord(query)]; ok {
			ans = append(ans, values[0])
			continue
		}
		if values, ok := casesDict[toCasesWord(query)]; ok {
			ans = append(ans, values[0])
			continue
		}
		if values, ok := vowelDict[toVowelWord(query)]; ok {
			ans = append(ans, values[0])
			continue
		}
		ans = append(ans, "")
	}
	return ans
}

func toWordsWord(word string) string {
	return word
}

func toCasesWord(word string) string {
	return strings.ToLower(word)
}

func toVowelWord(word string) string {
	return strings.Map(func(char rune) rune {
		switch char {
		case 'a', 'e', 'i', 'o', 'u':
			return '*'
		default:
			return char
		}
	}, strings.ToLower(word))
}
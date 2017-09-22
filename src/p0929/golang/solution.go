package main

import (
	"strings"
)

func numUniqueEmails(emails []string) int {
	dict := make(map[string]struct{})
	for _, email := range emails {
		email = normalize(email)
		dict[email] = struct{}{}
	}
	return len(dict)
}

func normalize(email string) string {
	parts := strings.Split(email, "@")
	local, domain := parts[0], parts[1]
	local = strings.Split(local, "+")[0]
	local = strings.Replace(local, ".", "", -1)
	return local + "@" + domain
}

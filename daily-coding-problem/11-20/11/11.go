package main

import (
	"fmt"
	"strings"
)

func autocomplete(pre string, words []string) []string {
	ans := []string{}

	for i := 0; i < len(words); i++ {
		if strings.HasPrefix(words[i], pre) {
			ans = append(ans, words[i])
		}
	}
	return ans
}
func main() {
	words := []string{"dog", "deer", "deal"}
	pre := "de"

	fmt.Println(autocomplete(pre, words))
}

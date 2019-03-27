/*
This problem was asked by Microsoft.

Given a dictionary of words and a string made up of those words (no spaces),
return the original sentence in a list. If there is more than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string
"thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string
"bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
*/

package main

import "fmt"

func valid(dict []string, s string) bool {
	for _, r := range dict {
		if r == s {
			return true
		}
	}
	return false
}

func reconstruct(dict []string, s string) []string {
	a := []string{}
	// fmt.Println("string:", s)
	for i := 0; i <= len(s); i++ {
		curr := s[:i]
		// fmt.Println("curr", curr)
		if valid(dict, curr) {
			fmt.Println("valid word:", curr)
			fmt.Println("string to pass in:", s[i:])
			a = reconstruct(dict, s[i:])
			sum := 0
			for _, w := range a {
				sum += len(w)
			}
			if len(curr)+sum == len(s) {
				return append([]string{curr}, a...)
			}
		}
	}
	return a
}

func r2(dict []string, s string) []string {
	a := []string{}

	dp := make([]int, len(s)+1)
	dp[0] = 1

	for i := 1; i <= len(s); i++ {
		for j := 0; j < i; j++ {
			if dp[j] > 0 && valid(dict, s[j:i]) {
				dp[i] = len(s[j:i])
				break
			}
		}
	}

	for iter := len(s); iter != 0; iter -= dp[iter] {
		a = append([]string{s[iter-dp[iter] : iter]}, a...)
	}

	return a
}

func main() {
	d1 := []string{
		"quick",
		"brown",
		"the",
		"fox",
	}
	s1 := "thequickbrownfox"
	fmt.Println(r2(d1, s1))

	// d2 := []string{
	// 	"bed",
	// 	"bath",
	// 	"bedbath",
	// 	"and",
	// 	"beyond",
	// }
	// s2 := "bedbathandbeyond"
	// fmt.Println(reconstruct(d2, s2))

	// d3 := []string{"a", "aa", "aaa", "aaaa", "aaaaa"}
	// s3 := "aaaaab"

	// fmt.Println(reconstruct(d3, s3))
}

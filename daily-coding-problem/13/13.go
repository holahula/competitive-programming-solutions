/*
Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
*/

package main

import "fmt"

func substring(s string, k int) int {

	front := 0
	curr := 0
	ans := 1

	m := make(map[string]int)

	// fmt.Println("s:", s, "length s:", len(s), "k:", k)
	for curr < len(s) {
		// fmt.Println(front, curr, ans)
		// fmt.Println("char:", curr, string(s[curr]))
		m[string(s[curr])]++
		// fmt.Println(m, len(m))

		for len(m) > k {
			// fmt.Println("exceed distinct char count:", len(m), k)
			m[string(s[front])]--
			if m[string(s[front])] == 0 {
				delete(m, string(s[front]))
			}
			front++
			// fmt.Println(m)
		}

		if curr-front+1 > ans {
			ans = curr - front + 1
		}

		curr++
	}
	return ans
}

func main() {
	s := "abcbd"
	k := 3
	fmt.Println(substring(s, k))

	// m := make(map[string]int)

	// fmt.Println(len(m))
	// m["l"] = 2
	// m["k"] = 2
	// fmt.Println(len(m))

}

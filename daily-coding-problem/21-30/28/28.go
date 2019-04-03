/*
This problem was asked by Palantir.

Write an algorithm to justify text. Given a sequence of words and an integer line length k,
return a list of strings which represents each line, fully justified.

More specifically, you should have as many words as possible in each line. There should be at
least one space between each word. Pad extra spaces when necessary so that each line has exactly length k.
Spaces should be distributed as equally as possible, with the extra spaces, if any, distributed starting from the left.

If you can only fit one word on a line, then you should pad the right-hand side with spaces.

Each word is guaranteed not to be longer than k.

For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]
 and k = 16, you should return the following:

["the  quick brown", # 1 extra space on the left
"fox  jumps  over", # 2 extra spaces distributed evenly
"the   lazy   dog"] # 4 extra spaces distributed evenly
*/

package main

import "fmt"

func format(arr [][]string) []string {
	ans := []string{}
	for i := 0; i < len(arr); i++ {
		curr := ""
		for j := 0; j < len(arr[i]); j++ {
			// if j%2 == 1 {
			// 	fmt.Println(j, len(arr[i][j]))
			// }
			curr += arr[i][j]
		}
		ans = append(ans, curr)
	}
	return ans
}

func justify(arr []string, k int) []string {
	ans := [][]string{}

	for i := 0; i < len(arr); {
		ll, line := 0, []string{}

		line = append(line, arr[i])
		ll += len(arr[i])
		i++

		if ll < k {
			line = append(line, " ")
			ll++
		}

		for i < len(arr) && ll+len(arr[i]) <= k {
			// insert word
			line = append(line, arr[i])
			ll += len(arr[i])
			i++

			if i < len(arr) && ll+1+len(arr[i]) <= k {
				line = append(line, " ")
				ll++
			}
		}

		// pad spaces to fill line
		space := 1
		for ll < k {
			line[space] += " "
			ll++
			space = (space + 2) % len(line)
		}
		ans = append(ans, line)
	}
	return format(ans)
}
func main() {
	list := []string{"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"}
	ans := justify(list, 16)

	for i := 0; i < 16; i++ {
		fmt.Print("-")
	}
	fmt.Println()
	for i := range ans {
		fmt.Println(ans[i])
	}
}

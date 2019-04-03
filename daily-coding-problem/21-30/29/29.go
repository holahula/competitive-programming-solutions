/*
This problem was asked by Amazon.

Run-length encoding is a fast and simple method of encoding strings.
The basic idea is to represent repeated successive characters as a single count and character.
For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string to be encoded have no digits
and consists solely of alphabetic characters. You can assume the string to be decoded is valid.
*/

package main

import (
	"fmt"
	"strconv"
)

func encode(s string) string {
	a := ""
	for i := 0; i < len(s); {
		j, count, curr := i, 1, s[i]
		for j+1 < len(s) && s[j+1] == curr {
			count++
			j++
		}
		i += count
		a += strconv.Itoa(count) + string(curr)
	}
	return a
}

func main() {
	fmt.Println(encode("AAAABBBCCDAA"))
}

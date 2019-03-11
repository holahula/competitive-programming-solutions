/*

This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.

*/
package main

import (
	"fmt"
	"strconv"
)

func decode(msg string) int {
	size := len(msg)
	dp := make([]int, size+1)

	dp[0] = 1
	dp[1] = 1

	for i := 2; i <= size; i++ {
		single, _ := strconv.Atoi(msg[i-1 : i])
		double, _ := strconv.Atoi(msg[i-2 : i])

		if single > 0 && single <= 9 {
			dp[i] += dp[i-1]
		}
		if double >= 10 && double <= 26 {
			dp[i] += dp[i-2]
		}
		// fmt.Println(i, single, double)
		// fmt.Printf("%v\n", dp)
	}

	return dp[size]

}

func main() {
	str := "123"
	ans := decode(str)
	fmt.Println(ans)
}

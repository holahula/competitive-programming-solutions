/*
This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

package main

import (
	"fmt"
	"math"
)

func consec(arr []float64) float64 {
	incl := arr[0]
	excl := float64(0)

	for i := 1; i < len(arr); i++ {
		exclNew := math.Max(incl, excl)
		incl = excl + arr[i]
		excl = exclNew
		// fmt.Println(i, incl, excl)
	}

	return math.Max(incl, excl)
}

func main() {
	arr := []float64{5, 1, 1, 5}

	fmt.Println(consec(arr))
}

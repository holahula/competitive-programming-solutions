/*
Find the minimum number of adjacent swaps in a binary array to minimize the number of adjacent pairs
of (0, 1) or (1, 0)

IN OTHER WORDS

Minimum number of adjacent swaps to split the array into [0...01...1]
*/

package main

import (
	"fmt"
	"math"
)

func reverse(arr []int) []int {
	rev := []int{}

	for i := len(arr) - 1; i > -1; i-- {
		rev = append(rev, arr[i])
	}
	return rev
}

func moves(arr []int) int {
	sum := 0
	ones := 0
	for i := 0; i < len(arr); i++ {
		if arr[i] == 1 {
			ones++
			sum += (i + 1) - ones
		}

	}
	return sum
}

func main() {
	arr := []int{1, 0, 1, 0, 0, 0, 0, 1}
	rev := reverse(arr)
	fmt.Println(math.Min(float64(moves(arr)), float64(moves(rev))))
}

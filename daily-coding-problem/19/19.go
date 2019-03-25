/*
This problem was asked by Facebook.

A builder is looking to build a row of N houses that can be of K different colors.
He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to build the
nth house with kth color, return the minimum cost which achieves this goal.
*/
package main

import (
	"fmt"
	"math"
)

// returns the min cost that allows you to paint house i color j
func minPrev(arr []int, index int) int {
	min := 1<<(32<<(^uint(0)>>32&1)-1) - 1
	// fmt.Println("minArr, index to avoid:", arr, index)
	for i := 0; i < len(arr); i++ {
		if arr[i] < min && i != index {
			min = arr[i]
		}
	}
	// fmt.Println("min", min)
	return min
}

func ans(arr []int) int {
	min := float64(arr[0])
	for i := 0; i < len(arr); i++ {
		min = math.Min(float64(min), float64(arr[i]))
	}
	return int(min)
}

func minCost(arr [][]int, n int, k int) int {
	// make solution array [][]
	sol := make([]int, k)
	prevArr := make([]int, k)
	// manually populate 1st houses
	for j := 0; j < k; j++ {
		sol[j] = arr[0][j]
	}
	for i := range sol {
		prevArr[i] = sol[i]
	}

	// iterate through houses 1 - n
	for i := 1; i < n; i++ {
		for j := 0; j < k; j++ {
			// fmt.Println(i, j)
			// minPast := minPrev(prevArr, j)
			// fmt.Println("curr:", arr[i][j], "min prev:", minPast)
			sol[j] = arr[i][j] + minPrev(prevArr, j)
		}
		for i := range sol {
			prevArr[i] = sol[i]
		}
	}
	return ans(sol)
}

func main() {
	a := [][]int{
		{6, 1, 2, 3},
		{4, 5, 6, 7},
		{1, 4, 2, 9},
	}

	fmt.Println(minCost(a, len(a), len(a[0])))
}

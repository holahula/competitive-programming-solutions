/*
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

package main

import "fmt"

func main() {
	var arr, post []int
	len := len(arr)

	// var post []int
	// test := [3]int{3, 2, 1}
	// len := len(test)

	for i := 0; i < len; i++ {
		sum := 1
		for j := 0; j < len; j++ {
			if i == j {
				continue
			} else {
				sum *= arr[j]
				// sum *= test[j]
			}
		}
		post = append(post, sum)
	}
	fmt.Printf("%v \n", post)
}

/*
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

package main

import "fmt"

// brute force
func bf(arr []int) {
	var post []int

	len := len(arr)

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

// prefix and suffix product

func pref(arr []int) {

	len := len(arr)

	prod := make([]int, len)
	pre := make([]int, len)
	post := make([]int, len)

	pre[0] = arr[0]
	post[len-1] = arr[len-1]

	for i := 1; i < len; i++ {
		pre[i] = pre[i-1] * arr[i]
	}
	for i := len - 2; i >= 0; i-- {
		post[i] = post[i+1] * arr[i]
	}

	for i := 0; i < len; i++ {
		if i == 0 {
			prod[i] = post[i+1]
		} else if i == len-1 {
			prod[i] = pre[i-1]
		} else {
			prod[i] = pre[i-1] * post[i+1]
		}
	}

	fmt.Printf("%v\n", prod)
}

func main() {
	arr := []int{1, 2, 3, 4, 5}
	bf(arr)
	pref(arr)
}

// [2, 3, 6]

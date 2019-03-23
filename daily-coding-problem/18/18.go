/*
This problem was asked by Google.

Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.
*/

package main

import (
	"fmt"
)

type operations interface {
	popLeft()
	popRight()
	pushLeft()
	pushRight()
}

type deque struct {
	len int
	arr []int
}

func (dq *deque) popLeft() {
	dq.arr = dq.arr[1:]
	dq.len--
}
func (dq *deque) popRight() {
	dq.arr = dq.arr[:len(dq.arr)-1]
	dq.len--
}
func (dq *deque) pushLeft(a int) {
	dq.arr = append([]int{a}, dq.arr...)
	dq.len++
}

func (dq *deque) pushRight(a int) {
	dq.arr = append(dq.arr, a)
	dq.len++
}

func max(arr []int, k int) {

}

func bf(arr []int, k int) {
	for i := 0; i < len(arr)-k+1; i++ {
		sub := arr[i : i+k]
		fmt.Println(sub)
		max := sub[0]
		for i := 0; i < k; i++ {
			if sub[i] > max {
				max = sub[i]
			}
		}
		fmt.Println(max)
	}
}

func main() {
	arr := []int{10, 5, 2, 7, 8, 7}
	k := 3
	bf(arr, k)
	max(arr, k)
}

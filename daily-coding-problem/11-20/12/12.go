/*
Part A
------
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns
the number of unique ways you can climb the staircase. The order of the steps matters.

Part B
------
What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X?
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/

package main

import "fmt"

func staircaseA(n int) int {
	prev := 1
	curr := 2
	next := 0

	if n == 1 {
		return 1
	} else if n == 2 {
		return 2
	} else {
		for i := 3; i <= n; i++ {
			next = prev + curr
			prev = curr
			curr = next
		}
	}
	return curr
}

func staircaseB(n int, x []int) int {
	steps := make([]int, n+5)
	// fmt.Println("test")
	for i := 0; i < n+5; i++ {
		steps[i] = 0
	}
	steps[0] = 1
	// fmt.Printf("%v\n", steps)

	for i := 1; i <= n; i++ {
		for j := 0; j < len(x); j++ {
			if i-x[j] >= 0 && steps[i-x[j]] != 0 {
				steps[i] += steps[i-x[j]]
			}
		}
	}
	// fmt.Println(steps)
	return steps[n]
}

func main() {
	N := 6
	X := []int{1, 3, 5}
	fmt.Println(staircaseA(N))
	fmt.Println(staircaseB(N, X))
}

package main

import (
	"fmt"
	"math"
)

func swap(i *int, j *int) {
	tmp := *i
	*i = *j
	*j = tmp
}

func split(arr []int) int {
	len := len(arr)
	j := 0
	for i := 0; i < len; i++ {
		if arr[i] <= 0 {
			swap(&arr[i], &arr[j])
			j++
		}
	}
	return j
}

func solvePos(arr []int) int {

	len := len(arr)

	for i := 0; i < len; i++ {
		arr[i]--
	}
	// this is disgusting
	for i := 0; i < len; i++ {
		if int(math.Abs(float64(arr[i]))) < len && arr[int(math.Abs(float64(arr[i])))] >= 0 {
			arr[int(math.Abs(float64(arr[i])))] = -arr[int(math.Abs(float64(arr[i])))]
		}
	}

	for i := 0; i < len; i++ {
		if arr[i] > 0 {
			return i + 1
		}
	}
	return len + 1
}

func main() {
	arr := []int{1, 1, 2}

	ans := solvePos(arr[split(arr):])
	fmt.Printf("first missing positive int: %d\n", ans)
}

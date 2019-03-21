/*
This problem was asked by Twitter.

You run an e-commerce website and want to record the last N order ids in a log.
Implement a data structure to accomplish this, with the following API:
record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
You should be as efficient with time and space as possible.

*/

package main

import "fmt"

type api interface {
	record(i int) []int
	get_last(i int) int
}
type log struct {
	arr  []int
	iter int
	size int
}

func (l *log) record(i int) {
	if len(l.arr) == l.size {
		l.arr[l.iter%l.size] = i
	} else {
		l.arr = append(l.arr, i)
	}
	l.iter++
}

func (l *log) getLast(i int) int {
	return l.arr[(l.iter-i)%l.size]
}

func main() {
	n := 5
	l := log{
		arr:  make([]int, n),
		iter: 0,
		size: n,
	}
	for i := 1; i < 7; i++ {
		l.record(i)
	}

	fmt.Println(l.arr)

	fmt.Println(l.getLast(2))
}

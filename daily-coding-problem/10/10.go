/*
This problem was asked by Apple.

Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.
*/

package main

import (
	"fmt"
	"time"
)

type f func(i int)

func job(i int) {
	dur := 1 * time.Second
	fmt.Println("job", i, "will run for:", dur)
	time.Sleep(dur)
	fmt.Println("job", i, "completed at", time.Now())
}

func jobScheduler(fn f, n int) {
	i := 1
	for {
		dur := time.Duration(n) * time.Millisecond
		time.Sleep(dur)
		go fn(i)
		i++
	}
}

func main() {
	jobScheduler(job, 5000)
}

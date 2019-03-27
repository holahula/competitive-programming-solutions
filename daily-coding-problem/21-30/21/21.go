/*
This problem was asked by Snapchat.

Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/
package main

import (
	"fmt"
	"math"
	"sort"
)

type Pair struct {
	start int
	end   int
}

func numClassrooms(intervals []Pair) int {
	starts, ends := []int{}, []int{}
	for i := 0; i < len(intervals); i++ {
		starts = append(starts, intervals[i].start)
		ends = append(ends, intervals[i].end)
	}

	sort.Ints(starts)
	sort.Ints(ends)

	i, j, cr, maxCR := 0, 0, 0, 0

	for i < len(starts) && j < len(ends) {
		// another classroom is needed for this period
		if starts[i] < ends[j] {
			cr++
			maxCR = int(math.Max(float64(cr), float64(maxCR)))
			i++
		} else {
			// previous lecture ended, 1 less cr needed for this period
			cr--
			j++
		}
	}

	return maxCR
}

func main() {
	list := []Pair{
		{30, 75},
		{0, 50},
		{60, 150},
		{10, 120},
	}

	fmt.Println(numClassrooms(list))
}

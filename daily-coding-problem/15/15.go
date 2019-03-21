/*
This problem was asked by Facebook.

Given a stream of elements too large to store in memory, pick a random element from the stream with uniform probability.
*/
package main

import (
	"math/rand"
	"time"
)

func random(min, max int) int {
	rand.Seed(time.Now().Unix())
	return rand.Intn(max-min) + min
}

func choose(stream []int) int {
	element := 0

	for i := 0; i < len(stream); i++ {
		if random(1, i+1) == 1 {
			element = stream[i]
		}
	}
	return element
}

func main() {
	stream := []int{}

	choose(stream)
}

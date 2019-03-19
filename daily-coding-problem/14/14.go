/*
This problem was asked by Google.

The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.
*/
package main

import (
	"fmt"
	"math"
	"math/rand"
)

// square 1 * 1 L= 1u
// circle area = pi / 4 (equation is (x-0.5)^2+(y-0.5)^2=0.5^2)
// ratio of points inside circle to outside circle = pi / 4
// 4 * points inside / total points

func monteCarlo(points int) float64 {
	inside := 0.0
	for i := 0; i < points; i++ {
		randX := rand.Float64()
		randY := rand.Float64()
		if i%100 == 0 {
			fmt.Println(randX, randY)

		}
		if (math.Pow(randX, 2) + math.Pow(randY, 2)) < 1 {
			inside++
		}
	}
	return 4 * inside / float64(points)
}
func main() {
	// number of random simulations to run
	points := 1000
	fmt.Printf("%.3f\n", monteCarlo(points))
}

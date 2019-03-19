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
	"runtime"
	"time"
)

func init() {
	runtime.GOMAXPROCS(runtime.NumCPU())
}
func monteCarlo(points int) float64 {
	inside := 0.0
	for i := 0; i < points; i++ {
		randX := rand.Float64()
		randY := rand.Float64()

		if (math.Pow(randX, 2) + math.Pow(randY, 2)) < 1 {
			inside++
		}
	}
	return 4 * inside / float64(points)
}

func monteCarloV2(points int) float64 {
	cpus := runtime.NumCPU()
	threads := points / cpus

	results := make(chan float64, cpus)
	for i := 0; i < cpus; i++ {
		go func() {
			inside := float64(0.0)
			r := rand.New(rand.NewSource(time.Now().UnixNano()))

			for j := 0; j < threads; j++ {
				randX, randY := r.Float64(), r.Float64()

				if (math.Pow(randX, 2) + math.Pow(randY, 2)) < 1 {
					inside++
				}
			}
			results <- 4 * inside / float64(threads)
		}()
	}
	total := 0.0
	for i := 0; i < cpus; i++ {
		total += <-results
	}
	return total / float64(cpus)
}

func main() {
	// number of random simulations to run
	points := 1000000

	start := time.Now()
	fmt.Printf("%.3f %d\n", monteCarlo(points), time.Since(start))

	start = time.Now()
	fmt.Printf("%.3f %d\n", monteCarloV2(points), time.Since(start))

}

/*
This problem was asked by Jane Street.

cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.
*/
package main

import "fmt"

type Pair struct {
	a, b interface{}
}

func cons(a, b interface{}) Pair {
	return Pair{a, b}
}
func car(p Pair) interface{} {
	return p.a
}
func cdr(p Pair) interface{} {
	return p.b
}

func main() {
	fmt.Println(car(cons("a", 42)))
}

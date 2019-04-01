/*

This problem was asked by Facebook.

Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.

*/

package main

import "fmt"

type Queue interface {
	pop()
	push(string)
	match(string) bool
	len() bool
}
type queue struct {
	arr []string
}

func NewQueue() Queue {
	return &queue{
		arr: []string{},
	}
}
func (q *queue) len() bool {
	if len(q.arr) == 0 {
		return true
	}
	return false
}
func (q *queue) pop() {
	q.arr = q.arr[:len(q.arr)-1]
}

func (q *queue) push(a string) {
	q.arr = append(q.arr, a)
}

func (q *queue) match(a string) bool {
	if q.arr[len(q.arr)-1] == "{" && a == "}" {
		return true
	} else if q.arr[len(q.arr)-1] == "(" && a == ")" {
		return true
	} else if q.arr[len(q.arr)-1] == "[" && a == "]" {
		return true
	}
	return false
}

func balance(s string) bool {
	// round, curly, square := 0, 0, 0
	q := NewQueue()
	for i := 0; i < len(s); i++ {
		c := string(s[i])
		if c == "{" || c == "(" || c == "[" {
			q.push(c)
		} else if c == "}" || c == ")" || c == "]" {
			if q.match(c) {
				q.pop()
			}
		}
	}
	if q.len() == true {
		return true
	}
	return false
}

func main() {
	fmt.Println(balance("([)]"))
	fmt.Println(balance("([])[]({})"))
	fmt.Println(balance("[({})]"))
	fmt.Println(balance("[][][][][]"))
}

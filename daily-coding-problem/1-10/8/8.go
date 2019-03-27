/*
This problem was asked by Google.

A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.
*/

package main

import "fmt"

type node struct {
	val   string
	left  *node
	right *node
}

type tree struct {
	root *node
}

func check(node *node, val string) bool {
	if node == nil {
		return true
	}
	if node.val == val {
		if check(node.left, val) && check(node.right, val) {
			return true
		}
	}
	return false
}

func unival(node *node) int {
	sum := 0
	if node == nil {
		return 0
	}
	if check(node, node.val) {
		sum++
	}
	left := unival(node.left)
	right := unival(node.right)

	sum += (left + right)
	return sum
}

func main() {
	root := node{val: "1", left: &node{val: "1", left: nil, right: &node{val: "1", left: nil, right: nil}}, right: &node{val: "1", left: nil, right: nil}}

	ans := unival(&root)
	fmt.Println(ans)

}

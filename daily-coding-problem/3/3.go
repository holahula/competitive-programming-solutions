/*
This problem was asked by Google.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
*/

package main

import (
	"fmt"
)

type Node struct {
	val   string
	left  *Node
	right *Node
}

var vals []string

func serialize(node *Node) {
	if node != nil {
		vals = append(vals, node.val)
		serialize(node.left)
		serialize(node.right)
	} else {
		vals = append(vals, "#")
	}
}

//a = append(a[:i], a[i+1:]...)
func deserialize(vals []string) *Node {
	value := vals[0]
	vals = append(vals[:0], vals[1:]...)
	if value == "#" {
		return nil
	}
	node := Node{val: value, left: deserialize(vals), right: deserialize(vals)}

	return &node
}

func print(node *Node) {
	if node != nil {
		fmt.Printf("%s\n", node.val)
		print(node.left)
		print(node.right)
	}
}
func main() {
	// fmt.Printf("Hello")
	root := Node{val: "root", left: &Node{val: "left", left: &Node{val: "left.left", left: nil, right: nil}, right: nil}, right: &Node{val: "right", left: nil, right: nil}}

	serialize(&root)

	fmt.Printf("%v\n", vals)

	node := deserialize(vals)

	print(node.left.left)
	// fmt.Print("Deserialize done\n")
	// vals = nil
	// serialize(node)
	// fmt.Printf("Second serialize: %v\n", vals)
}

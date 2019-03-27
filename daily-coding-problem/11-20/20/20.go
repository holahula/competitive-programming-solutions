/*
This problem was asked by Google.

Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
*/

package main

import "fmt"

type node struct {
	val  int
	next *node
}

type singlyLinkedList struct {
	root *node
}

func getLength(sll singlyLinkedList) int {
	i := 1

	node := sll.root

	for node.next != nil {
		node = node.next
		i++
	}
	return i
}

func intersect(a singlyLinkedList, b singlyLinkedList) node {
	lenA := getLength(a)
	lenB := getLength(b)
	fmt.Println(lenA, lenB)
	nodeA := a.root
	nodeB := b.root

	if lenA > lenB {
		for i := 0; i < lenA-lenB; i++ {
			nodeA = nodeA.next
		}
	} else {
		for i := 0; i < lenB-lenA; i++ {
			nodeB = nodeB.next
		}
	}

	for nodeA.val != nodeB.val {
		nodeA, nodeB = nodeA.next, nodeB.next
	}

	return *nodeA
}
func main() {
	A := &singlyLinkedList{
		root: &node{
			val: 3,
			next: &node{
				val: 7,
				next: &node{
					val: 8,
					next: &node{
						val:  10,
						next: nil,
					},
				},
			},
		},
	}

	B := &singlyLinkedList{
		root: &node{
			val: 99,
			next: &node{
				val: 1,
				next: &node{
					val: 8,
					next: &node{
						val:  10,
						next: nil,
					},
				},
			},
		},
	}

	fmt.Println(intersect(*A, *B).val)
}

/*
This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list. 
Instead of each node holding next and prev fields, it holds a field named both,
which is an XOR of the next node and the previous node. Implement an XOR linked list; 
it has an add(element) which adds the element to the end, and a get(index)
which returns the node at index.

*/
#include <string>
#include <iostream>

using namespace std;

struct Node {
    string val;
    struct Node* nx;
};

struct Node* xOR (struct Node* prev, struct Node* next){
    return (struct Node*) ( (uintptr_t) (prev) ^ (uintptr_t) (next) );
}

void add (Node* &tailRef, string val){
    Node* newNode = new Node();
    newNode->val = val;
    newNode->nx = xOR(tailRef, nullptr);

    if(tailRef){
        tailRef->nx = xOR(newNode, xOR(tailRef->nx, nullptr));
    }

    tailRef = newNode;
}

struct Node* get(Node *head, int index){
    int iter = index;
    Node *curr = head;
    Node *prev = nullptr;
    Node *next;

    while (iter > 1){
        next = xOR(prev, curr->nx);
        prev = curr;
        curr = next;
    }
    return curr;
}

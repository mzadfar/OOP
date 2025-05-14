'''
 * @file test021.py
 * @author M. Z.
 * @brief Inserting a node at the beginning of a linked list
 * array
 * @date 2025-02-18
 *
 * @copyright Copyright (c) 2025
'''
import sys

class Node:
    def __init__(self, data,next):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insertNodeAtBegining(self, beginingNode):
        new_node = Node(beginingNode,self.head)
        new_node.next = self.head
        self.head = new_node

    def printList(self):
        temp = self.head
        print("The list is: ", end=" ")
        while(temp):
            print(temp.data, end=" ")
            temp = temp.next
        print() #newline

# Example Usage
ll = LinkedList()
numOfNodes = int(input("How many node in the linked list? "))
for i in range(0, numOfNodes):
    beginingNode = int(input("Enter a number as node: "))
    ll.insertNodeAtBegining(beginingNode)
    ll.printList()  

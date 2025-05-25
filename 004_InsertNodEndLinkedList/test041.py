'''
 * @file test041.py
 * @author M. Z.
 * @brief Inserting a node at the end of a linked list
 * array
 * @date 2025-03-03
 *
 * @copyright Copyright (c) 2025
'''
import sys

class Node:
    def __init__(self, data, next):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None

    def insertNodeAtEndOfList(self, data):
        temp1 = Node(data, None)
        if (self.head == None):
            self.head= temp1
        else:
            temp2 = self.head
            while (temp2.next != None):
                temp2 = temp2.next
            temp2.next = temp1
        return self.head

    def printList(self):
        temp = self.head
        print("The list is: ", end=" ")
        while temp != None:
            print(temp.data, end=" ")
            temp = temp.next
        print() #newline
    
LL = LinkedList()  # Empty linked list
LL.head = LL.insertNodeAtEndOfList(9)
LL.head = LL.insertNodeAtEndOfList(8)
LL.head = LL.insertNodeAtEndOfList(7)
LL.head = LL.insertNodeAtEndOfList(6)
LL.head = LL.insertNodeAtEndOfList(5)
LL.printList()           
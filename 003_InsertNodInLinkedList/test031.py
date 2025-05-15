'''
 * @file test31.py
 * @author M. Z.
 * @brief Inserting a node in the linked list
 * array
 * @date 2025-03-03
 *
 * @copyright Copyright (c) 2025
'''
import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insertNodeInList(self, data, position):
        temp1 = Node(data)
        if (1 == position):
            temp1.next = self.head
            self.head = temp1
        else:
            temp2 = self.head
            for i  in range(1, position -1):
                temp2 = temp2.next
            temp1.next = temp2.next
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
LL.head = LL.insertNodeInList(9,1)
LL.head = LL.insertNodeInList(8,2)
LL.head = LL.insertNodeInList(7,3)
LL.head = LL.insertNodeInList(6,4)
LL.head = LL.insertNodeInList(5,5)
LL.printList()           
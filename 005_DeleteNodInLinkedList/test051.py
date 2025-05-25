'''
 * @file test051.py
 * @author M. Z.
 * @brief Deleting a node in the linked list
 * array
 * @date 2025-03-04
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
            for i in range(0, position-2):
                temp2 = temp2.next
            temp1.next = temp2.next
            temp2.next = temp1
        return self.head

    def deleteNodeInList(self, position):
        temp1 = self.head
        if (1 == position):
            self.head = temp1.next
        else:
            for i in range(0, position-2):
                temp1 = temp1.next
            temp2 = temp1.next
            temp1.next = temp2.next
        return self.head

    def printList(self):
        temp = self.head
        print("The list is: ", end = " ")
        while (temp != None):
            print(temp.data, end = " ")
            temp = temp.next
        print()

LL = LinkedList()
LL.head = LL.insertNodeInList(9,1)
LL.head = LL.insertNodeInList(8,2)
LL.head = LL.insertNodeInList(7,3)
LL.head = LL.insertNodeInList(6,4)
LL.head = LL.insertNodeInList(5,5)
LL.printList()
position = int(input("Enter a position to be deleted: "))
LL.deleteNodeInList(position)
LL.printList()
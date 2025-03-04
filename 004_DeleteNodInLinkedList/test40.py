'''
 * @file test40.py
 * @author M. Z.
 * @brief Deleting a node in the linked list
 * array
 * @date 2025-03-04
 *
 * @copyright Copyright (c) 2025
'''
import sys

def Node(data,next):
    return [data, next]

def insertNodeInList(head, data, position):
    temp1 = Node(data,None)
    if (1 == position):
        temp1[1] = head
        head = temp1
    else:
        temp2 = head
        for i in range(0,position-2):
            temp2 = temp2[1]
        temp1[1] = temp2[1]
        temp2[1] = temp1
    return head

def deleteNodeInList(head, position):
    temp1 = head
    if (1 == position):
        head = temp1[1]
    else:
        for i in range(0,position-2):
            temp1 = temp1[1]
        temp2 = temp1[1]
        temp1[1] = temp2[1]
    return head

def printList():
    temp = head
    print("The list is: ", end = " ")
    while (temp != None):
        print (temp[0], end = " ")
        temp = temp[1]
    print()

head = None  # Empty linked list
head = insertNodeInList(head, 9,1)
head = insertNodeInList(head, 8,2)
head = insertNodeInList(head, 7,3)
head = insertNodeInList(head, 6,4)
head = insertNodeInList(head, 5,5)
printList()
position = int(input("Enter a position to be deleted: "))
head = deleteNodeInList(head,position)
printList()
'''
 * @file test040.py
 * @author M. Z.
 * @brief Inserting a node at the end of a linked list
 * array
 * @date 2025-03-03
 *
 * @copyright Copyright (c) 2025
'''
import sys

def Node(data, next):
    return [data, next]

def insertNodeAtEndOfList(head, data):
    temp1 = Node(data, None) #temp1[0] = data, temp1[1] = next
    if (head == None):
        head = temp1
    else:
        temp2 = head
        while (temp2[1] != None):
           temp2 = temp2[1]
        temp2[1] = temp1
    return head

def printList():
  temp = head
  print("The list is: ", end=" ")
  while temp != None:
    print(temp[0], end=" ")
    temp = temp[1]
  print() #newline
    
head = None  # Empty linked list
head = insertNodeAtEndOfList(head, 9)
head = insertNodeAtEndOfList(head, 8)
head = insertNodeAtEndOfList(head, 7)
head = insertNodeAtEndOfList(head, 6)
head = insertNodeAtEndOfList(head, 5)
printList()



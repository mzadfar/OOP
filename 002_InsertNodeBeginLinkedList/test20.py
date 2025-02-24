'''
 * @file test20.py
 * @author M. Z.
 * @brief Inserting a node at the beginning of a linked list
 * array
 * @date 2025-02-18
 *
 * @copyright Copyright (c) 2025
'''
import sys

def createNode(data, next):
  return [data, next]

def insertNodeAtBegining(head, data):
  beginningNode = createNode(data, head)
  return beginningNode

def printList():
  temp = head
  print("The list is: ", end=" ")
  while temp != None:
    print(temp[0], end=" ")
    temp = temp[1]
  print() #newline

# Example usage:
head = None  # Empty linked list
numOfNodes = int(input("How many node in the linked list? "))
for i in range(0, numOfNodes):
  beginingNode = int(input("Enter a number as node: "))
  head = insertNodeAtBegining(head, beginingNode) 
  printList()
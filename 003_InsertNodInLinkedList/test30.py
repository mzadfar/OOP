import sys

def Node(data, next):
    return [data, next]

def insertNodeInList(head, data, position):
    temp1 = Node(data, None)
    if (1 == position):
        temp1[1] = head
        return temp1
    else:
        temp2 = head
        for i in range(1,position -1):
           temp2 = temp2[1]
        temp1[1] = temp2[1]
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
head = insertNodeInList(head, 9,1)
head = insertNodeInList(head, 8,2)
head = insertNodeInList(head, 7,3)
head = insertNodeInList(head, 6,4)
head = insertNodeInList(head, 5,5)
printList()



/**
 * @file project4_v2.cpp
 * @author M. Z.
 * @brief Sorted doubly-linked list, queue and stack: We will develop three
common linked data structures, a sorted doubly-linked list, a simple queue, and
a simple stack.
 * @version 0.1
 * @date 2024-08-06
 *
 * @copyright Copyright (c) 2024
 *
Introduction for some basic classes
The primary data structure will be a doubly-linked list that is always
maintained in a sorted order, along with a simple node class that will be able
to be used by the sorted list. Keep in mind that, while the list will fully
utilize the node class, the node class really shouldn’t know anything about a
list – it is just a node, and it might be used in other data structures (like
the others being developed for this project!).

LinkedNodeClass: this class will be used to store individual nodes of a
doubly-linked data structure. This class should end up being quite short and
simple – no significant complexity is needed, desired, or allowed.

SortedListClass: this class will be used to store a doubly-linked list in an
always-sorted way, such that the user does not specify where in the list a value
should be inserted, but rather the new value is inserted in the correct place to
maintain a sorted order.

Additional Data Structures
After implementing and fully testing the above classes, move on to implementing
these additional data structures, which should be able to be completed very
quickly due to their restricted functionality.

FIFOQueueClass: this will be a “first-in-first-out queue” data structure. You
should be able to use the LinkedNodeClass you developed above to very quickly
develop and test this data structure. If written correctly, this class should be
very short and simple, and should not require a significant chunk of the time to
implement. Since the FIFO queue has such restricted functionality, it is quite
straight forward to develop, especially since the bidirectional LinkedNodeClass
is already available and can be used to make this a very short and simple data
structure to implement. This class will be used to store a simple
first-in-first-out queue data structure.

LIFOStackClass: this will be a “last-in-first-out stack” data structure. You
should be able to use the LinkedNodeClass you developed above to very quickly
develop and test this data structure. If written correctly, this class should be
very short and simple, and should not require a significant chunk of the time to
implement. Since the LIFO stack has such restricted functionality, it is quite
straight forward to develop, especially since the bidirectional LinkedNodeClass
is already available and can be used to make this a very short and simple data
structure to implement. This class will be used to store a simple
last-in-first-out stack data structure.
 */

#include <iostream>

using namespace std;

#include "FIFOQueueClass.h"
#include "LIFOStackClass.h"
#include "SortedListClass.h"

int main() {

  SortedListClass testList;
  // SortedListClass temp(testList);

  testList.printForward();

  testList.insertValue(42);
  testList.insertValue(20);
  testList.insertValue(2);
  testList.insertValue(4);
  testList.insertValue(20);
  testList.insertValue(3);

  SortedListClass temp(testList);

  testList.printForward();
  cout << testList.getNumElems() << endl;

  int m = 1000;
  testList.getElemAtIndex(3, m);
  cout << "Surprise!" << endl;
  cout << m;

  int theVal;
  testList.removeFront(theVal);
  testList.printForward();
  testList.printBackward();
  cout << "the Value in the front is: " << theVal << endl;

  testList.removeLast(theVal);
  testList.printForward();
  testList.printBackward();
  cout << "the Value in the Last is: " << theVal << endl;

  /* copy constructor */
  // SortedListClass temp(testList);
  temp.insertValue(233333333);
  temp.printForward();
  testList.printForward();

  LIFOStackClass testStackList;
  testStackList.print();
  cout << testStackList.getNumElems() << endl;

  testStackList.push(42);
  testStackList.push(20);
  testStackList.push(35);
  testStackList.push(1);
  testStackList.push(-4);
  testStackList.print();
  int tempNum;
  testStackList.pop(tempNum);
  testStackList.print();
  cout << "Stack Num is: " << tempNum;

  FIFOQueueClass testQueueList;
  testQueueList.print();
  cout << testQueueList.getNumElems() << endl;

  testQueueList.enqueue(42);
  testQueueList.enqueue(20);
  testQueueList.enqueue(35);
  testQueueList.enqueue(1);
  testQueueList.enqueue(-4);
  testQueueList.print();
  int tempNumQueue;
  testQueueList.dequeue(tempNumQueue);
  testQueueList.print();
  cout << "Queue Num is: " << tempNumQueue << endl;

  return 0;
}
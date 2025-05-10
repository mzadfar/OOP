#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Function to generate binary numbers between 1 and `n` using the
// queue data structure
void generate(int n) {
  // create an empty queue and enqueue 1
  queue<string> q;
  q.push("1");

  // run `n` times
  int i = 1;
  while (i++ <= n) {
    // append 0 and 1 to the front element of the queue and
    // enqueue both strings
    q.push(q.front() + "0");
    q.push(q.front() + "1");

    // dequeue front element after printing it
    cout << q.front() << ' ';
    q.pop();
  }
}

int main() {
  int n = 16;
  generate(n);

  return 0;
}
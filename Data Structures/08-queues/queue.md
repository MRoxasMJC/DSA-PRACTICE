# The Queue
The queue is a data structure that follows the First-In, First-Out principle.
This means that the first element added to the queue is the first one to be removed.
The queue can be used as a buffer in computer systems for speed mismatches between two devices that communicate with each other, like the keyboard and CPU.
These are also used in Operating System algorithms like CPU Scheduling and Memory Management.

It is like a line of people waiting to be served, where the first person in line is the first person served.

---
## Terminology:
* Front/head: The first entry that will be removed from the queue.
* Rear/tail: The last entry in the queue, that is, the most recently added.
   
## Three types of queues:
1. ### Simple Queue
   * Insertion is only allowed at the rear
   * Deletion is only allowed from the front
   * Can be implemented using a linked list or array. 
2. ### Double Ended Queue (Deque)
   * In a deque, insertion and deletion can be performed on both ends.
3. ### Priority Queue
   * Each element is assigned a **priority** in this queue, and deletion is always based on this priority, not just position.

## Queue Operations
1. Enqueue: Adds an element to the rear of the queue. If the queue is full, an overflow error occurs
2. Dequeue: Removes the element from the front of the queue. If the queue is empty, an underflow error occurs
3. Peek()/Front(): Returns the element at the front without removing it. 
4. Size: Returns the number of elements in the queue
5. IsEmpty: Returns true if the queue is empty, otherwise false. 
6. isFull: Returns true if the queue is full, otherwise false.

## Implementation Issues
There is one main issue when implementing this data structure.
When we dequeue(), we'd have to move the elements forward, resulting in O(n) time.
To avoid this, we can define three variables f, r, and n:

* f is the index of the cell of Q storing the front of the queue. If the queue is nonempty, this is the index of the element to be removed by dequeue.
* r is an index of the cell of Q following the rear of the queue. If the queue is not full, this is the index where the element is inserted by enqueue.
* n is the current number of elements in the queue.

When we dequeue an element, n is decremented and f is incremented. 
When we enqueue an element, n is incremented and r is incremented.

However, there is a problem with this. If we keep enque-ing and deque-ing the same element
N times, f and r will reach the array's capacity and go out of bounds. In other words, f = r  = N. 

A circular array can help with this, where we can use the modulo (%) to wrap it around!
This is important because queues remove from the front, and wrapping around 
lets us use that free space. 


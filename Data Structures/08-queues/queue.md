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
3. Peek/Front: Returns the element at the front without removing it. 
4. Size: Returns the number of elements in the queue
5. IsEmpty: Returns true if the queue is empty, otherwise false. 
6. isFull: Returns true if the queue is full, otherwise false. 

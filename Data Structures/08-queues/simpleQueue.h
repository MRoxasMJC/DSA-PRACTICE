#ifndef SIMPLEQUEUE_H
#define SIMPLEQUEUE_H

#include <string>
#include <exception>

// This is a fixed-array simple queue!
class QueueEmpty : public std::exception {
    private:
        std::string m;
    public:
        QueueEmpty(const std::string mInp = " ") {
            m = "Queue Empty: " + mInp;
        }

        virtual const char* what() {
            return m.c_str();
        }
};

template <typename T>
class Queue {
    private:
        T* data;
        int f; // index of front element
        int r; // index of rear, if the array is not full
        int n;  // size of queue;
        int N = 0; // capacity;
    public:
        Queue(int cap = 10);
        ~Queue();
        int size() const;
        bool isEmpty() const;
        const T& front() const;
        void enqueue (const T& e);
        void dequeue();
        void printAll();

};

template <typename T>
Queue<T>::Queue(int cap) {
    if (cap < 5) {
        cap = 5;
    }

    N = cap;
    data = new T[N];
    f = r = n = 0;
}

template <typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template <typename T>
int Queue<T>::size() const {
    return n;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return n == 0;
}

template <typename T>
const T& Queue<T>::front() const {
    if (isEmpty()) {
        throw QueueEmpty("Cannot access front");
    }

    return data[f];
}

template <typename T>
void Queue<T>::enqueue(const T& e) {
    if (n == N) {
        throw std::overflow_error("Queue is full") ;
    }

    data[r] = e;
    n++;
    r = (r + 1) % N;
}

template <typename T>
void Queue<T>::dequeue() {
    if (isEmpty()) {
        throw QueueEmpty("Can't dequeue!");
    }

    f = (f + 1) % N;
    n--;
}

template <typename T>
void Queue<T>::printAll() {
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return;
    }

    std::cout << "[ " ;
    for (int i = f; i < r; i++) {
        std::cout << data[i] << " " ;
    }
    std::cout << "]" << std::endl;
}


#endif
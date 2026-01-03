#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
    private:
        int numElements;
        int capacity;
        T* container;

        void _resize();
    public:
        Stack(int initCapacity = 5);
        ~Stack();
        void push(const T& element);
        T pop();
        const T& top() const;
        int size() const;
        bool isEmpty() const;
        void printAll() const;
};

template <typename T>
Stack<T>::Stack(int initCapacity) {
    if (initCapacity < 1) {
        initCapacity = 1;
    }

    numElements = 0;
    capacity = initCapacity;
    container = new T[capacity];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] container;
    capacity = 0;
    numElements = 0;
}

template <typename T>
void Stack<T>::_resize() {
    int newCapacity = capacity * 2;
    auto* newContainer = new T[newCapacity];

    for (int i = 0; i < numElements; i++) {
        newContainer[i] = container[i];
    }

    delete[] container;
    container = newContainer;
    capacity = newCapacity;
}

template <typename T>
void Stack<T>::push(const T& element) {
    if (numElements == capacity) {
        _resize();
    }

    container[numElements] = element;
    numElements++;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return 1;
    }

    T topElement = top();
    numElements--;

    return topElement;
}

template <typename T>
const T& Stack<T>::top() const {
    return container[size() - 1];
}

template <typename T>
int Stack<T>::size() const {
    return numElements;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return size() == 0;
}

template<typename T>
void Stack<T>::printAll() const {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }

    std::cout << "[ ";
    for (int i = 0; i < size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << "]" << std::endl;
}

#endif
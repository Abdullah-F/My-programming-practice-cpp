/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: abdullah-fadhel
 *
 * Created on November 8, 2016, 2:45 AM
 */

#include <iostream>
#include <algorithm>

using namespace std;

template<class Var>
class MaxTreap {
private:
    Var* maxTreapArray;
    int size;
    int maxSize;

    Var parent(int index) {
        return index / 2;
    }

    Var leftChild(int index) {
        return 2 * index;
    }

    Var rightChild(int index) {
        return (2 * index) + 1;
    }

    void siftUp(int index) {
        int parentIndex = parent(index);

        while (index > 1 &&
                (maxTreapArray[parentIndex] < maxTreapArray[index])) {

            swap(maxTreapArray[parentIndex], maxTreapArray[index]);
            index = parent(index);
            parentIndex = parent(index);
        }
    }

    void siftDown(int index) {
        int maxIndex = index;
        Var leftChildeIndex = leftChild(index);
        if (leftChildeIndex <= size && maxTreapArray[leftChildeIndex] >
                maxTreapArray[maxIndex])
            maxIndex = leftChildeIndex;

        Var rightChildIndex = rightChild(index);
        if (rightChildIndex <= size && maxTreapArray[rightChildIndex] >
                maxTreapArray[maxIndex])
            maxIndex = rightChildIndex;

        if (index != maxIndex) {
            swap(maxTreapArray[maxIndex], maxTreapArray[index]);
            siftDown(maxIndex);
        }
    }

public:

    MaxTreap(Var arr_size) {
        maxTreapArray = new Var(arr_size);
        size = 0;
        maxSize = arr_size;
        maxTreapArray[0] = -1;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return maxSize;
    }

    Var getMaxElement() {
        if (size > 0)
            return maxTreapArray[1];
        return maxTreapArray[0];

    }

    Var extractMax() {
        if (size > 0) {
            Var result = maxTreapArray[1];
            maxTreapArray[1] = maxTreapArray[size];
            size = size - 1;
            siftDown(1);
            return result;
        }

        return -1;
    }

    void insert(Var newNode) {
        if (size == maxSize) {
            cout << "Error Not Enough Space !" << endl;
            return;
        }
        size++; //increase size when adding new element.
        maxTreapArray[size] = newNode; //add at the leftmost vacant node in the treap
        siftUp(size); //sift up the added node
    }

    Var remove(int index) {
        if (size > 0) {
            if (index > 0) {
                maxTreapArray[index] = maxTreapArray[1] + 10;
                siftUp(index);
                return extractMax();
            }
        }

        return -1;
    }

    void changePriority(int index, Var newPriority) {
        Var oldPriority = maxTreapArray[index];
        maxTreapArray[index] = newPriority;

        if (oldPriority > newPriority)
            siftDown(index);
        else
            siftUp(index);
    }

    Var &operator[](int index) {
        if (index > size || index < 1) {
            cout << "Index out of bounds" << endl;
            // return first element.
            return maxTreapArray[0];
        }
        return maxTreapArray[index];
    }

};

int main() {
    int size;
    cout << "Enter Max Size\n";
    cin >> size;
    MaxTreap<int> myTreap(size);
    cout << "Enter number of elements\n";
    cin >> size;
    int value;

    while (size > 0) {
        cin >> value;
        myTreap.insert(value);
        size--;
    }
    while (myTreap.getSize() != 0) {
        cout << "Max " << myTreap.extractMax() << endl;
        cout << "size  " << myTreap.getSize() << endl;
    }

    cout << endl;
    for (int i = 1; i <= myTreap.getSize(); i++) {
        cout << myTreap[i] << " ";
    }
    cout << endl;

    return 0;
}


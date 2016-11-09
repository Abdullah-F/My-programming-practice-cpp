/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: abdullah-fadhel
 *
 * Created on November 9, 2016, 4:39 AM
 */

#include <iostream>

using namespace std;


int parent(int index) {
    return (index - 1) / 2;
}


int leftChild(int index) {
    return (2 * index) + 1;
}


int rightChild(int index) {
    return (2 * index) + 2;
}

template<class Var>
void siftUp(int index ,Var* maxTreapArray) {
    int parentIndex = parent(index);

    while (index > 0 &&
            (maxTreapArray[parentIndex] < maxTreapArray[index])) {

        swap(maxTreapArray[parentIndex], maxTreapArray[index]);
        index = parent(index);
        parentIndex = parent(index);
    }
}

template<class Var>
void siftDown(int index,Var* maxTreapArray,int size) {
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
        siftDown(maxIndex,maxTreapArray,size);
    }
}

template<class Var>
void buildHeap(Var* array_to_be_sorted, int size) {
    int sizeBy2 = size / 2;

    for (int i = sizeBy2; i >= 0; i--) {
        siftDown(i,array_to_be_sorted,size);
    }
}

template<class Var>
Var extractMax(Var* maxTreapArray,int size) {
            Var result = maxTreapArray[0];
            maxTreapArray[0] = maxTreapArray[size];
            size = size - 1;
            siftDown(0,maxTreapArray,size);
            return result;
    }

template<class Var>
Var heapSort(Var* maxTreapArray,int size) {
    buildHeap(maxTreapArray,size);
    
    for(int i = size-1 ; i > 0 ; i--)
    {
        swap(maxTreapArray[0] ,maxTreapArray[i]);
        siftDown(0,maxTreapArray,i-1);
    }

}

int main() {

    int size;
    cout << "Enter Max Size\n";
    cin >> size;
    int* arr = new int(size);
    cout << "Enter number of elements\n";
    cin >> size;
    int value;
    
    for (int i = 0; i < size; i++) {
        cin >> value;
        arr[i] = value;
    }
    
    
   heapSort(arr,size);    
//    for (int i = size-1;i > -1 ; i--) {
//        cout << "Max " << extractMax(arr,size) << endl;
//    }
//    
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;


    return 0;
}


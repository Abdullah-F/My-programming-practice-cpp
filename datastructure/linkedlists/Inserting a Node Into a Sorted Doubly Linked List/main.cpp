/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: abdullah-fadhel
 *
 * Created on September 10, 2016, 3:55 PM
 */

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* previous;
};

template<class T>
T* SortedInsert(T *head,int data)
{
    T * to_be_inserted = new Node() , *traversal = head;
    to_be_inserted->data = data;
    bool is_inserted = false;
   if(!head){
       to_be_inserted->next = nullptr;
       to_be_inserted->previous = nullptr;
       return to_be_inserted;
   }
 
    if(head->data > to_be_inserted->data)
    {
        to_be_inserted->next = head;
        head->previous = to_be_inserted;
        to_be_inserted->previous = nullptr;
        return to_be_inserted;
    }else if(head->next){
            
    traversal = head->next;
    while(traversal)
    {   
        if(traversal->data > to_be_inserted->data)
        {
            to_be_inserted->next = traversal;
            traversal->previous->next = to_be_inserted;
            to_be_inserted->previous = traversal->previous;
            traversal->previous = to_be_inserted;
            is_inserted =true;
            if(!traversal->previous)
                head = traversal;
            break;
            
        }
        if(!traversal->next)
            break;
        traversal = traversal->next;
        
    }
    }
    
    if(!is_inserted)
    {
        traversal->next = to_be_inserted;
        to_be_inserted->previous = traversal;
        to_be_inserted->next = nullptr;
    }
    
    return head;
}

template<class T>
T* read_double_linkedlist()
{
    T *head_and_tail , *head , *tail , *temp;
    head_and_tail = new Node();
    head_and_tail->next = nullptr;
    
    int  size;
    cin >> size;
    
    if(size <= 0)
            return head_and_tail;
    head = new Node();
    head->previous = nullptr;
    
    cin >> head->data;
    temp = head;
    
    for(int i = 0 ; i < size-1 ; i++)
    {
        temp->next = new Node();
        cin >> temp->next->data;
        temp->next->previous = temp;
        temp = temp->next;
    }
    
    (tail= temp)->next = nullptr;
    
    head_and_tail->next = head;
    head_and_tail->previous = tail;
    
    return head_and_tail;
    
}

template<class T>
T* Reverse(T* head)
{
    if(!head)
        return nullptr;
    
    T* temp = head , *temp2 = head->next , *temp3;
    
    while(temp2)
    {
      temp3 = temp->next;
      temp->next = temp->previous;
      temp->previous = temp3;
      temp = temp2;
      
      temp2 = temp2->next;
      
              
    }
    
      temp3 = temp->next;
      temp->next = temp->previous;
      temp->previous = temp3;
      
     
    
    return temp;
}

int main(int argc, char** argv) {

    Node* head_and_tail = read_double_linkedlist<Node>();
   
    Node* temp = Reverse(head_and_tail->next);
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    
    
    cout << endl;
    
    return 0;
}


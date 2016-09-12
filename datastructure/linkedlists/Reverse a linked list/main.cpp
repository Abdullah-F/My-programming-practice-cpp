#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* Reverse(Node *head)
{
  if(!head) return nullptr;
 
  if(!head->next) return head;
    
  Node *ptr = head , *ptr1 = head->next , *ptr2 = head->next->next;
    ptr->next = NULL;
    
    do{
        ptr1->next = ptr;
        ptr = ptr1;
        ptr1 = ptr2;
        if(ptr1)
        ptr2 = ptr2->next;
    }while(ptr1);
        
        
    return ptr;
    
}


int GetNode(Node *head,int positionFromTail)
{
      Node* reversed_head = Reverse(head);
      int counter = 0 ;
      while(reversed_head != 0)
      {
          if(counter == positionFromTail)
              return reversed_head->data;
          reversed_head = reversed_head->next;
          counter++;
      }
}


int CompareLists(Node *headA, Node* headB)
{
  Node *traversalA = headA,*traversalB = headB;
  
  while(traversalA && traversalB)
  {
      if(traversalA->data != traversalB->data)
          return 0;
      
      traversalA = traversalA->next;
      traversalB = traversalB->next;
  }
  
  if(!traversalA && !traversalB)
      return 1;
  else return 0;
}

Node* Delete(Node *head, int position)
{
    Node* ptr = head;
    int counter = 0;
   if(head)
       {
       if(position == 0)
           head = head->next;
       else
           while(ptr->next)
           {
           if(counter == (position-1)){
               ptr->next = ptr->next->next;
               break;
           }
           ptr = ptr->next;
           counter++;
       }
   }
    return head;
}


Node* RemoveDuplicates(Node *head)
{
    int counter = 0;
    Node* traversal = head , *traversal2 = head->next;
    while(traversal2)
    {
        if(traversal->data == traversal2->data)
        {
            head = Delete(head,counter);
            counter--;
        }
        traversal = traversal->next;
        traversal2 = traversal2->next;
        counter++;
    }
    return head;
}


bool hasCycle(Node head) {
   
    return false;
}

Node* MergeLists(Node *headA, Node* headB)
{
    Node merged_head;
    if(!headA && !headB)
        return nullptr;
    if(!headA && headB)
        return headB;
    else if(headA && !headB)
        return headA;
    else{
        
        Node* traversal = &merged_head;
        
        while(headA && headB)
        {
            
            
         if(headA->data == headB->data)
        {
            traversal->next = headA;
            headA = headA->next;
            headB = headB->next;
        }else if(headA->data < headB->data)
        {
            traversal->next = headA;
            headA = headA->next;
        }else
        {
            traversal->next = headB;
            headB = headB->next;
        }
         
         
         traversal = traversal->next;
   
        }
        if(!headA && headB)
            traversal->next = headB;
        else if(!headB && headA)
            traversal->next = headA;
        else
        traversal->next = nullptr;
        return merged_head.next;
        
    }
    
}

int FindMergeNode(Node *headA, Node *headB)
{
    int countera = 0 , counterb = 0;
    Node *head_a = headA,*head_b = headB;
    int result;
    while(head_a)
    {
        countera++;
        head_a = head_a->next;
    }
    
    while(head_b)
    {
        counterb++;
        head_a = head_b->next;
    }
    
    if(countera > counterb)
    {
        for(int i = 0 ; i < countera-counterb ; i++)
            headA = headA->next;
    }else
    {
        for(int i = 0 ; i < counterb-countera ; i++)
            headA = headA->next;
    }
    
    while(headA)
    {
        if(headA->next == headB->next)
        {
            result = headA->data;
            break;
        }
        headA = headA->next;
        headB = headB->next;
    }
    
    
    
    return result;
}


int main()
{
    Node* head = NULL , *head1 = NULL;
    int n;
    Node* itr;
    cin >> n;
    
    if(n > 0){
        head = new Node();
        cin >> head->data;
        head->next =nullptr;
        itr = head;
    }
    
    for(int i = 1 ; i < n ; i++ )
    {
        itr->next = new Node();
        itr = itr->next;
        itr->next = nullptr;
        cin >> itr->data;
    }
    
    
    
    ///////////////////
    cin >> n;
    
    if(n > 0){
        head1 = new Node();
        cin >> head1->data;
        head1->next =nullptr;
        itr = head1;
    }
    
    for(int i = 1 ; i < n ; i++ )
    {
        itr->next = new Node();
        itr = itr->next;
        itr->next = nullptr;
        cin >> itr->data;
    }
   
    Node* merged_head = MergeLists(head,head1);
    
    while(merged_head)
    {
        cout << merged_head->data << " ";
        merged_head = merged_head->next;
    }
    cout << endl;
    
    return 0;
}
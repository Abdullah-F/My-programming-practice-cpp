#include<iostream>
using namespace std;


typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

template<typename T>
void decode_huff(T * root,string s)
{
    if(!root) return;
    
    int i = 0;
    T* ptr = root;
    
    while(i < s.size())
    {
        if(s[i] == '1')
            ptr = ptr->right;
        else ptr = ptr->left;
        
        if(ptr->data != '\0' )
        {
            cout << ptr->data ;
            ptr = root;
        }
        i++;
        
    }
    
}


int main()
{
    
    return 0;
}
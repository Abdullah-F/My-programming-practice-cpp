#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
#include<sstream>
using namespace std;


int get_rotate(map<int,int> &panCake)
{
    map<int,int>::iterator itr = panCake.begin();
    int counter = 0;
    for(;itr != panCake.end() ; itr++)
    {
        if(itr->second == 0)
            return counter;
        counter++;
    }
    return -1;
}

template <typename T>
string NumberToString ( T Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}

string panCakeStr(map<int,int> &panCake)
{
    string sum = "" ;
    
    map<int,int>::iterator itr = panCake.begin();
    
   
    for(;itr != panCake.end() ; itr++)
    {
       
        
        sum += NumberToString(itr->second);
        
        
    }
    
    
    return sum;
}

void rotate(map<int,int> &panCake)
{
    map<int,int>::iterator itr = panCake.end() , itr1;
    itr--;
    int temp = itr->second;
    itr1 = itr;
    itr1--;
    
    while(true)
    {
     
     if(itr == panCake.begin())
         break;
     
     itr->second = itr1->second;
     itr1--;
     itr--;
     
    }
    
    itr = panCake.begin();
    itr->second = temp;
    
}

void swap(int& x1 , int& x2)
{
   int temp;
   
   temp = x1;
   x1 = x2;
   x2 = temp;
}

void flip(map<int,int> &panCake , int n , int k)
{
    int back , forward , counter;
     
    if(k == 0)
        k = n*2;
    
    
    
    if(k%2 == 0)
    {
        back    = k-2;
        forward = k+2;
    }
    else
    {
        back = k-1;
        forward = k+1;
    }
    
    
    
    if(n%2 == 0)
    {
        if(k%2 == 0)
        {
        counter = (n/2) -1;
        }
        else counter = (n/2);
            
        
        while(counter > 0)
        {
            
            
            swap(panCake[back],panCake[forward]);
            
            if(back == 0)
                back = (n*2)-2;
            else
            back -= 2;
            forward += 2;
            
            counter--;
        
            
        }
         
    }
    else{
        counter = n/2;
        
        while(counter > 0)
        {
            
            swap(panCake[back],panCake[forward]);
            
            if(back == 0)
                back = (n*2)-2;
            else
            back -= 2;
            
            forward += 2;
            
            counter--;
        }
        
    }
    
     
}

string flip1(map<int,int> panCake , int n , int k)
{
    int back , forward , counter;
     
    if(k == 0)
        k = n*2;
    
    
    
    if(k%2 == 0)
    {
        back    = k-2;
        forward = k+2;
    }
    else
    {
        back = k-1;
        forward = k+1;
    }
    
    
    
    if(n%2 == 0)
    {
        if(k%2 == 0)
        {
        counter = (n/2) -1;
        }
        else counter = (n/2);
            
        
        while(counter > 0)
        {
            
            
            swap(panCake[back],panCake[forward]);
            
            if(back == 0)
                back = (n*2)-2;
            else
            back -= 2;
            forward += 2;
            
            counter--;
        
            
        }
         
    }
    else{
        counter = n/2;
        
        while(counter > 0)
        {
            
            swap(panCake[back],panCake[forward]);
            
            if(back == 0)
                back = (n*2)-2;
            else
            back -= 2;
            
            forward += 2;
            
            counter--;
        }
        
    }
    
return panCakeStr(panCake);     
}


int main() {
    map<int,int> pancake;
    string original_panCake_position;
    
    map<int,char>::iterator itr;
    int n , m ,type , k , start , end;
    cin >> n >> m;
    
    if((n >= 3 && n <= 1000000) && (m >= 1 && m <= 1000000))
    {
    
    for(int i = 0 ; i < n*2 ; i+=2)
    {
        pancake[i] = i;
    }
    
    original_panCake_position = panCakeStr(pancake);
    
    
        
    
    for(int i = 0 ; i < m ; i++)
    {
        cin >> type >> k;
        
        if(k >= 0 && k < n)
        if(type == 1){
            while(k > 0)
            {
            rotate(pancake);
            k--;
            }
        }
        else if(type == 2)
        {
         flip(pancake,n,k);   
        }
            
        
    }
    
    bool is_found = false;
    
    for(int i = 0 ; i < n ; i++)
    {
      
      
      if(flip1(pancake,n,i) == original_panCake_position)
      {
          cout << 2 << " " << i << endl;
          is_found = true;
      }
      
    }
    
    if(!is_found)
    {
        cout << 1 << " " << n-get_rotate(pancake) << endl;
    }
    
    }
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<iomanip>
#include <algorithm>
#include<set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int size , mode;
    long int sum = 0;
    float mean , median;
    
    cin >> size;
    
    multiset<int> mySet;
    
    
    for(int i = 0 ; i < size ; i++)
    {
        cin >> mode;
       mySet.insert(mode);    
    }
    
    multiset<int>::iterator iter = mySet.begin();
    
    for(;iter != mySet.end() ; iter++)
    {
        sum += *iter;
    }
    
    cout << fixed << setprecision(1) <<  (double)sum/size << endl;
    
    iter = mySet.begin();
    mode = size/2;
    
    for(int i = 0 ; i <= mode ; i++)
    {
       
    if(i == mode)
    {
    if(size%2 == 0)
    {
        median = (*iter + *(--iter))/2.0;
    }
    else
    {
        median = *iter;
    }
    
    }
    
    
    iter++;
    }
    cout << fixed << setprecision(1) << median << endl;
    
    for(;iter != mySet.end() ; iter++)
    {
        sum += *iter;
    }
    
    
    iter = mySet.begin();
    mode =0;
    median = *iter;
    size =0;
    
    
    for(;iter != mySet.end() ; iter++)
    {
        if(median == *iter)
            mode++;
        else
        {
            if(mode > size)
            {
                size = mode;
                sum = *(--iter);
                median = *(++iter);
                mode = 1;
            }else
            {
                median = *iter;
                mode = 1;
            }
        }
        
        if( ++iter == mySet.end())
        {
            --iter;
            if(mode > size)
            {
                size = mode;
                sum = *(--iter);
                median = *(++iter);
                mode = 1;
            }else
            {
                median = *iter;
                mode = 1;
            }
        }
        else
            --iter;
            
        
    }
    cout << sum;
        
        
    
    
    return 0;
}

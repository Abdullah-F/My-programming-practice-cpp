#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include <map>
#include<iomanip>
using namespace std;

float evenSet(multiset<float>::iterator iter ,int size,bool flag,int n =0)
{
    
    if(flag)
    {
        for(int i = 0;;i++)
        {
            if(i == size)
            {
                 
                return (*iter + *(--iter))/2.0;
            }
            iter++;
        }
       
    }else
    {
        
        for(int i = n ; ; i--)
        {
            
            if(i == size)
            {
                if(n%2 == 0)
                return (*iter + *(--iter))/2.0;
                 return (*iter + *(++iter))/2.0;
            }
            iter--;
        }
    }
}

float oddSet(multiset<float>::iterator iter ,int size,bool flag,int n =0)
{
    if(flag)
    {
        for(int i = 0;;i++)
        {
            if(i == size)
            {
                
                return *iter;
            }
            iter++;
        }
        
    }else
    {
        
        for(int i = n ; ; i--)
        {
            if(i == size)
            {
                return *iter;
            }
            iter--;
        }
    }
    
}

int main() {
    int nNumbers ;
    float q1,q2,q3;
    multiset<float> rowData;
    
    
    
    
    cin >> nNumbers;
    float  numbers[nNumbers];
    float  frequencies[nNumbers];
    
    for(int i = 0 ; i < nNumbers ; i++)
    {
        cin >> q1;
        numbers[i] =q1;
        
    }
    
    for(int i = 0 ; i < nNumbers ; i++)
    {
        cin >> q1;
        frequencies[i] =q1;
        
    }
    
    for(int i = 0 ; i < nNumbers ; i++)
    {
        for(int j = 0 ; j < frequencies[i] ; j++)
           rowData.insert(numbers[i]);
    }
    
    nNumbers = rowData.size();
    multiset<float>::iterator iter = rowData.begin();
    
    if(nNumbers%2 == 0)
    {
        q2 = evenSet(rowData.begin(),nNumbers/2,true);    
    }
    else
        q2 = oddSet(rowData.begin(),nNumbers/2,true);
    
    if((nNumbers/2)%2 == 0)
    {
        q1 = evenSet(rowData.begin(),nNumbers/4,true);
    }
    else
        q1 = oddSet(rowData.begin(),nNumbers/4,true);
        
    
    if((nNumbers-(nNumbers/2))%2 == 0 || nNumbers%2 != 0)
    {
        if((nNumbers%2 != 0 && ((nNumbers/2)%2 == 0)))
        q3 = evenSet(rowData.end(),((nNumbers - (nNumbers/2))/2)+(nNumbers/2),false,nNumbers);
        else
            q3 = oddSet(rowData.end(),((nNumbers - (nNumbers/2))/2)+(nNumbers/2),false,nNumbers);
    }
    else
    {
        
        q3 = oddSet(rowData.end(),((nNumbers - (nNumbers/2))/2)+(nNumbers/2),false,nNumbers);
    }
    
    iter = rowData.begin();
    cout << fixed  << setprecision(1)<<q3-q1 << endl;
    
    
    
       
    return 0;
}
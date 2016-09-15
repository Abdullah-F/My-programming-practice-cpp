#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s , sub;
    long long int m;
    getline(cin,s);
    bool repeated = false , all_the_same = true;
    cin >> m;
    
    for(int i = 1 ; i <= s.length()/2 ; i++)
    {
        if(s.substr(0,i) == s.substr(i,i))
        {
            sub = s.substr(0,i);
            repeated = true;
            for(int j = 1 ; j < sub.length() ; j++)
            {
                if(sub[j] != sub[j-1])
                    all_the_same = false;
            }
            if(!all_the_same)
            break;
           
        }
    }
    
    if(sub.length() >= 1)
    for(int i = 0 ; i < s.length() ; i+=sub.length())
    {
        
        if(s.substr(i,sub.length()) != sub)
            repeated = false;
    }
    
    if(sub.length() >= 1)
    if(all_the_same)
    {
        cout << m << endl;
        return 0;
    
    }
    
    if(!repeated)
    {
        cout << (long long int) (m/s.length())%(1000000000+7) << endl;
        
    }else
    {
        cout << (long long int) (m/sub.length())%(1000000000+7)<< endl;
    }
    
    return 0;
}

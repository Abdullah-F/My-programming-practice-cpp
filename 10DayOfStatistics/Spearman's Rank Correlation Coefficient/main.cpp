#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
using namespace std;



int main() {
    map<float,int> x_map , y_map;
    int n;
    cin >> n;
    
    
    float x[n],y[n];
    
    for(int i = 0 ;i< n ; i++)
    {
        cin >> x[i];
        x_map[x[i]] =0;
    }
    
    map<float,int>::iterator itr = x_map.begin();
    
    for(int i = 0 ;itr != x_map.end() ; itr++,i++)
    {
         itr-> second = i;
    }
    
    for(int i = 0 ;i< n ; i++)
    {
        cin >> y[i];
        y_map[y[i]] =0;
    }
    
    itr = y_map.begin();
    for(int i = 0 ;itr != y_map.end() ; itr++,i++)
    {
         itr-> second = i;
    }
    double d_squared = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        d_squared += pow(x_map[x[i]]-y_map[y[i]],2);
    }
    
    cout <<fixed << setprecision(3) << round(1000*(1-((6 * d_squared)/(n*(pow(n,2)-1)))))/1000 << endl;
    
    
      
  
}


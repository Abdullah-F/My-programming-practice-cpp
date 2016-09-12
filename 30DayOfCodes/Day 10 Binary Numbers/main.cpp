#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>


using namespace std;



int main(){
        
    int x[6][6];
    
    for(int i = 0 ; i< 6 ; i++)
    {
        for(int j = 0 ; j < 6  ; j++)
         cin >> x[i][j];
       
    }
    
    float sum =0 , result = -10000;
    
    for(int i = 0 ; i< 4 ; i++)
    {
       for(int j = 0 ; j < 4  ; j++)
       {
           
               for(int jj = j ; jj < j+3 ; jj++)
               {
                   sum += x[i][jj];
               
               }
               
                   sum += x[i+1][j+1];
                   
               for(int jj = j ; jj < j+3 ; jj++)
               {
                   sum += x[i+2][jj];
               }
               
                   
           
           if(sum > result)
           {
               result = sum;
           }
                    
           sum = 0;
       }
       
        
               
    }
    
    cout <<  result << endl;
    
    
    return 0;
}

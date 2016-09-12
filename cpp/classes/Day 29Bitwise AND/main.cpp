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
#include <unordered_map>

using namespace std;


int main(){
    int t;
    
    int a_and_b = 0;
    cin >> t;
    
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
         
        
        for(int i = 1 ; i <= n ;i++)
        {
          
            for(int j = i+1 ; j <= n ; j++)
          {
                cout << i << "," << j << "  ";
                if(static_cast<int>(i&j) > a_and_b && static_cast<int>(i&j) < k )
              
                {
                  a_and_b = static_cast<int>(i&j);
              
                }
          }
            cout << endl;
        }
        
        cout << a_and_b << endl;
        a_and_b =0;
    }
    
}

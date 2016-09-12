#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n;
    cin >> n;
    vector<int > to_be_sorted(n,0);
    
    for(int i = 0 ; i < n ;i++)
    {
        cin >> to_be_sorted[i];
    }
    
    sort(to_be_sorted.begin(), to_be_sorted.end());
    
    for(int i = 0 ; i< n ; i++)
    {
        cout <<  to_be_sorted[i] <<" " ;
    }
    cout << endl;
    
      
    return 0;
}

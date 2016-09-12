#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,q;
    cin >> n;
    vector<int> vect(n,0);
   
    for(int i = 0 ; i < n ; i++)
        cin >> vect[i];
    cin >> n;
    vector<int>::iterator itr;
    for(int i = 0 ; i < n ; i++)
    {
        
        cin >> q;
        itr = lower_bound(vect.begin() , vect.end() , q);
        if(*itr == q)
            cout << "Yes " << (itr-vect.begin())+1 << endl;
        else
            cout << "No " << (itr-vect.begin())+1 << endl;
       
    }
   
    return 0;
}


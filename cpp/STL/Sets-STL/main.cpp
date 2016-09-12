#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int n , q1 ,q2;
    set<int> mySet;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> q1 >> q2;
        
        if(q1 == 1)
        {
            mySet.insert(q2);
        }else if(q1 == 2)
        {
            mySet.erase(q2);
        }
        else if(q1 == 3)
        {
            if(mySet.find(q2) != mySet.end())
                cout << "Yes\n";
            else cout << "No" << endl;
        }
    }
    return 0;
}

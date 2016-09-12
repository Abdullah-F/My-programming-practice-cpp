#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n , q;
    cin >> n;

    string str[n] , str2;
    
    for(int i = 0 ; i < n ; i++)
        cin >> str[i];
    
    cin >> q;
    int counter;
    while(q > 0)
    {
        cin >> str2;
        for(int i = 0 ; i < n ; i++)
        {
            if(str2 == str[i])
                ++counter;
        }
        cout << counter << endl;
        counter = 0;
        q--;
    }


    return 0;
}

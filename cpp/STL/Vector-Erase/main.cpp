#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    
    int n , num;
    cin >> n;
    vector<int> vec(n,0);
    
    for(int i = 0 ; i < n ; i++)
    {
        cin >> vec[i];
    }
    
    cin >> n;
    vec.erase(vec.begin()+n-1);
    
    cin >> n >> num;
    vec.erase(vec.begin()+n-1 , vec.begin()+num-1);
    
    cout << vec.size() << endl;
    for(int i = 0 ; i < vec.size() ; i++)
    {
        cout << vec[i] << " ";
    }


    return 0;
}

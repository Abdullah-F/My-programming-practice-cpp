#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int size , k;
    
    cin >> size >> k;
    
    int* arr = new int[size];
    
    for(int i = 0 ; i < size ; i++)
        cin >> arr[(i+size-k)%size];
    
    
    
    for(int i = 0 ; i < size ; i++)
        cout << arr[i] << " ";
    return 0;
}

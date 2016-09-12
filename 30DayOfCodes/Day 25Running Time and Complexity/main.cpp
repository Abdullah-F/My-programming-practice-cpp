#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n)
{
    if(n <= 1)
        return false;
    else if(n <= 3)
        return true;
    else if(n%2 == 0 || n%3 == 0)
    {
        return false;
    }
    else {
        int i = 5;
        while(n >= (i* i))
        {
            if(n%i == 0 || n%(i+2) == 0)
                return false;
            i+=6;
        }
        
    }
    return true;
        
}

int main() {
    int n , number;
    cin >> n;
    for(int i= 0 ; i < n ; i++){
        cin >> number;
        if(isPrime(number))
        {
            cout << "Prime" << endl;
        }else{
            cout << "Not prime" << endl;
        }
    }
    return 0;
}
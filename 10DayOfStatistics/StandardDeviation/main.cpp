#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    int size;
    float mean =  0 , sumOfSquaredDistances =  0 ,standardDeviation;
    
    cin >> size;
    
    float numbers[size];
    float distances[size];
    
    for(int i = 0 ;i < size ; i++ )
    {
        cin >> numbers[i];
        mean += numbers[i];
    }
    
    mean = mean/size;
    
    for(int i = 0 ; i < size ; i++)
    {
        distances[i] = pow(numbers[i]-mean,2);
        sumOfSquaredDistances+=distances[i];
    }
    
    standardDeviation = sqrt(sumOfSquaredDistances/size);
    
    cout <<fixed << setprecision(1) << standardDeviation << endl;

    return 0;
}

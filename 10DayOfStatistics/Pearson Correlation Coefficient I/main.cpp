#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

#define _3round(result)  round(result*1000)/1000

float get_standard_deviation(float* x , int size , float *mean = 0)
{
    float variance = 0;
    
    for(int i = 0 ; i < size ;i++)
    {
        *mean += x[i];
    }
    
    *mean = *mean/size;
    
    
    
    for(int i = 0 ; i < size ; i++)
    {
        variance += pow(x[i]-*mean,2);
    }
    
    variance =variance/size;
    
    
    return sqrt(variance);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
   
    int n,num;
    float xmean = 0 , ymean , x_std , y_std , co_variance = 0 , result =0;
    cin >> n;
    
    float x[n] , y[n];
    
    for(int i = 0 ; i < n ;i++)
    {
        cin >> x[i];        
    }
    
    for(int i = 0 ; i < n ;i++)
    {
        cin >> y[i];        
    }
    
    
    x_std = get_standard_deviation(x,n,&xmean);
    y_std = get_standard_deviation(y,n,&ymean);
    
    for(int i = 0 ; i < n ; i++)
    {
        co_variance += (x[i]-xmean)*(y[i]-ymean);
    }
    
    result = co_variance/( n * x_std * y_std );
    
    cout <<fixed << setprecision(3) <<  _3round(result) << endl;
    
    return 0;
}

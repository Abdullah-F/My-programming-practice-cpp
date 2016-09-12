#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    float sum_of_xi_cross_yi = 0 , sum_of_xi = 0 , sum_of_yi , sum_of_xiSquared = 0
    ,sum_of_xi_squared = 0 , x_mean , y_mean;
    
    int n = 5;
    
    float x[n],y[n];
    
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x[i] >> y[i];
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        sum_of_xi_cross_yi += x[i]*y[i];
        sum_of_xi += x[i];
        sum_of_yi += y[i];
        sum_of_xiSquared += pow(x[i],2);
        
    }
    sum_of_xi_squared = pow(sum_of_xi,2);
    
    x_mean = sum_of_xi/n;
    y_mean = sum_of_yi/n;
    
   double b = ( (n* sum_of_xi_cross_yi) - (sum_of_xi*sum_of_yi) )/
            (  (sum_of_xiSquared*n ) - sum_of_xi_squared );
    
    
   double a = y_mean - (b*x_mean);
   
   float result = a + ( b * 80 );
   
   cout << fixed << setprecision(3) <<  round(result * 1000)/1000 << endl;
    
    return 0;
}

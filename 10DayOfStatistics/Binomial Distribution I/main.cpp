#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    double result = (1+erf((250-214)/(20 * sqrt(2))))/2.0 , result2;
    
    cout << fixed << setprecision(4) << (round((result)*10000)/10000) << endl;
    
    
    return 0;
}

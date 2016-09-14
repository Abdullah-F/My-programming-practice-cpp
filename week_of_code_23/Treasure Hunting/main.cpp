#include <iostream>
#include<iomanip>
 
using namespace std;


int main() {
    long double x,y;
    long double a,b;
    cin >> x >> y >> a >> b;
    
    long double a_dash = -b , b_dash = a;
    
    long  double n , k;
    n = (y-((b/a)*x))/(b_dash - ((b*a_dash)/a));
    k = (x/a)-((a_dash/a)*n);
   
    
    cout << fixed << setprecision(12) << k << endl; 
    cout << fixed << setprecision(12) << n << endl;
    return 0;
}


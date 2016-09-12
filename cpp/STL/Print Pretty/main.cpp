#include <iostream>
#include <iomanip> 
#include<cmath>
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
         
         cout << setiosflags(ios::hex); 
         cout << nouppercase << setiosflags(ios::showbase)
                 << setw(0) <<(int)A << endl;
         
         
         cout << hex  << setw(15) <<right << setfill('_') 
               << noshowbase  << showpos <<fixed << setprecision(2) << B << endl;
         
         cout << setiosflags(ios::uppercase);
         cout << resetiosflags(ios::showpos); 
         cout << resetiosflags(ios::fixed);
         cout << dec << setprecision(9)
                 << scientific << C << endl;
                

                
 
        }
	return 0;

}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
 
 
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	unsigned long long N, S, P, Q, num;
	
	cin >> N >> S >> P >> Q;
 
	unsigned long long p_231 = static_cast<unsigned long long>(pow(2, 31));
	int *bit_array = new int[p_231 / 32];
	
        memset(bit_array, 0, sizeof(int) * (p_231 / 32));
 
	unsigned long long equation = S % p_231;
        
	bit_array[(equation/32)] |= (1 << (equation%32));
	
        unsigned long long result = 1;
 
	for (unsigned long long i = 1; i < N; i++) {
		num = equation * P + Q;
		equation = num % p_231;
 
		if (!(bit_array[(equation/32)] & (1 << (equation%32)))) {
			bit_array[(equation/32)] |= (1 << (equation%32));
			result++;
		}
	}
 
	cout << result << endl;
        
	delete[] bit_array;
 
	return 0;
}
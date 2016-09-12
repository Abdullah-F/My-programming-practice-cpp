#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    long int n , q , num , x , y , last_ans = 0;
    cin >> n;
    vector< vector<int> > a_list(n , vector<int>());
    cin  >> q;
    
    for(int i = 0 ; i < q ; i++ )
    {
        cin >> num >> x >> y ;
        if(num == 1)
        {
            a_list[(x^last_ans)%n].push_back(y);
            
        }else if(num == 2){
            last_ans = a_list[(x^last_ans)%n][y%a_list[(x^last_ans)%n].size()];
            cout << last_ans << endl;
        }
    }
    
    
    
    return 0;
}

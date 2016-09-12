#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int day1 , month1 , year1;
    int day2 , month2 , year2;
    
    cin >> day1 >> month1 >> year1;
    cin >> day2 >> month2 >> year2;
    
    if(day1 <= day2 )
    {
        
        if(month1 <= month2)
        {
            if(year1 <= year2)
            {
                cout << 0 << endl;
            }else
                cout << 10000 << endl;
        }else{
            if(year1 < year2)
                cout << 0 << endl;
            else if(year1 == year2)
                cout << 500 *(month1 - month2) << endl;
            else cout << 10000 << endl;
        }
    }else{
        
        if(month1 == month2)
        {
            if(year1 < year2)
            {
                cout << 0 << endl;
            }else if(year1 == year2){
                cout << 15 * (day1 - day2) << endl;
            }else cout << 10000 << endl;
        }else if(month1 > month2)
        {
            if(year1 > year2)
                cout << 10000 << endl;
            else if(year1 == year2)
            {
                cout << 500* (month1 - month2) << endl;
            }else cout << 0 << endl;
        }
        else if(month1 < month2){
            if(year1 <= year2)
                cout << 0 << endl;
            else
                cout << 10000 << endl;
        }
    }
    
    return 0;
}

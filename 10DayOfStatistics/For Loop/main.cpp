#include <iostream>
#include <cstdio>
using namespace std;

string numberName(int a) {
    if (a == 1)
        return "one";
    else if (a == 2)
        return "two";
    else if (a == 3)
        return "three";
    else if (a == 4)
        return "four";
    else if (a == 5)
        return "five";
    else if (a == 6)
        return "six";
    else if (a == 7)
        return "seven";
    else if (a == 8)
        return "eight";
    else if (a == 9)
        return "nine";
    else if(a%2 == 0)
        return "even";
    else
        return "odd";

                                    }

int main() {

    int a, b;
    cin >> a >> b;
    
    for(int i = a ; i <= b ; i++)
        cout << numberName(i) << endl;



    return 0;
}

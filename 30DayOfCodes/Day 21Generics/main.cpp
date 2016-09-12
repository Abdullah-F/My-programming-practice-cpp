#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printArray(T& x)
{
    for(int i = 0 ; i < x.size(); i++)
    {
        cout << x[i] << endl;
    }
}
int main() {
  
    vector<int> vInt{1, 2, 3};
    vector<string> vString{"Hello", "World"};
    
    printArray<vector<int>>(vInt);
    printArray<vector<string>>(vString);
    
    return 0;
}
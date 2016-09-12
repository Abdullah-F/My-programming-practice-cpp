#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    
    map<string,int> myMap;
    
    int q , score;
    string name;
    cin >> q;
    
    for(int i = 0 ; i < q ; i++)
    {
        cin >> score;
        
        if(score == 1)
        {
            cin >> name >> score;
            
            if(myMap.find(name) != myMap.end())
            {
             myMap[name] += score;   
            }else
            {
                myMap[name] = score;
            }
        }else if(score == 2){
            cin >> name;
            if(myMap.find(name) != myMap.end())
                myMap.erase(myMap.find(name));
            
        }else if(score == 3)
        {
            cin >> name;
            if(myMap.find(name) != myMap.end())
                cout << myMap[name] << endl;
            else cout << 0 << endl;
        }
    }
    

    return 0;
}

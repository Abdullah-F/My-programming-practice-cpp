#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi
#include <stdexcept>
using namespace std;

int main ()
{
    string str;
    cin >> str;
    
    int x;
    
    try{
    x = stoi(str,NULL,10);
    cout << x << endl;
    }
    catch(invalid_argument& inv){
        cout << "Bad String" << endl;
    }catch(out_of_range& outf){
        cout << "Bad String" << endl;
    }
    
}
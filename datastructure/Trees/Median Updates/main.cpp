#include<iostream>
#include<set>
#include<iomanip>
using namespace std;

string TrimString(string str)
  {
  bool dot = false;
  for(int i = 0 ; i < str.length() ; i++ )
  {
      if(str[i] == '.'){
          dot = true;
          break;
      }
  }
  char cr ;
  if(dot)
  for(int s=str.length()-1 ; s>0; --s)
    {
      cr = str[s]; 
    if(cr == '0' || cr == '.') 
        str.erase(s,1);
    else 
        break;
    if(cr == '.')
        break;
    }
  
  return str;
  }

int main() {
   multiset<int> mySet;
    char op;
    long int val, erased_elements, size, med1, med2, n;
    double median;
    string str;
    multiset<int>::iterator itr;
    mySet.insert(1);
   
    mySet.erase(1);
    cin >> n;
    while (n > 0) {
        cin >> op >> val;

        if (op == 'a') {
            mySet.insert(val);
            size = mySet.size();
        } else {
            erased_elements = erased_elements = mySet.size();
            if (erased_elements > 0) {

                itr = mySet.find(val);
                if (itr == mySet.end())
                    erased_elements = 0;
                else {
                    mySet.erase(itr);
                    size = mySet.size();
                    if (erased_elements != 1)
                        erased_elements = erased_elements - size;
                }

            }

        }

        if ((op == 'a' || (op == 'r' && erased_elements > 0)) && size > 0) {
            itr = mySet.begin();
            advance(itr, size / 2);

            if (size % 2 != 0) {
                cout << *itr << endl;
            } else {
                med1 = *itr;

                --itr;

                med2 = *itr;

                median = (med2 + med1) / 2.0;
                

                stringstream ss;
               
                ss << std::fixed << median; // outputs 5000000.550000
                ss >> str;
                str = TrimString(str);
                
                cout << str << endl;    
            }
        } else
            cout << "Wrong!" << endl;
        n--;
    }



    return 0;
}
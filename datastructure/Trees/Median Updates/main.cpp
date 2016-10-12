#include<iomanip>
#include<iostream>
#include<sstream>
#include<set>
#include <ext/pb_ds/assoc_container.hpp>//tree library (not used here in this code)
#include <ext/pb_ds/tree_policy.hpp>//tree library (not used here in this code)
using namespace std;

string TrimString(string str) {
    bool dot = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            dot = true;
            break;
        }
    }
    char cr;
    if (dot)
        for (int s = str.length() - 1; s > 0; --s) {
            cr = str[s];
            if (cr == '0' || cr == '.')
                str.erase(s, 1);
            else
                break;
            if (cr == '.')
                break;
        }

    return str;
}
int main() {
    /*
     idea : we keep tracking the median each time we add elements to the set
     */
    multiset<long int> mySet;
    char op;
    long int val, erased_elements, size, med1, med2, n;
    double median;
    string str;
    multiset<long int>::iterator median_itr , temp_itr ,temp_itr1;
    mySet.insert(1);

    mySet.erase(1);
    cin >> n;
    while (n > 0){
        cin >> op >> val;

        if (op == 'a') {
            mySet.insert(val);

            if (mySet.size() == 1)
                median_itr = mySet.begin();//median is the only element in the set
            else if (mySet.size() % 2 != 0 && val < *median_itr)//adding element smaller than the median
                median_itr--;//median goes back one step (if the new size is odd)
            else if (mySet.size() % 2 == 0 && val >= *median_itr)//adding >= or equal element
                median_itr++;//the median goes forward one step (if the new size is even)
        }else if(op == 'r')
        {
            temp_itr = median_itr;
            temp_itr1 = mySet.find(val);
            if(mySet.empty()){
                cout << "Wrong!" << endl;//can't delete from an empty set.
                n--;
                continue;
            }
            else if((mySet.size()-1) %2 != 0 && temp_itr1 == median_itr)//deleting the median itself.
                    median_itr--;//median goes back one step (if the new size is odd)
            else if((mySet.size()-1) %2 != 0 && val > *median_itr)//deleting an element greater than median
                median_itr--;//median goes back one step (if the new size is odd)
            else if((mySet.size()-1) %2 != 0 && val == *median_itr)//deleting an element equal the median,
                //but is not the median
            {
                if(distance(temp_itr1,median_itr) <= 0)
                    median_itr--;//median goes back one step (if the new size is odd and deleted element 
                //position is after the median.)
            }
            else if((mySet.size()-1) %2 == 0 && val < *median_itr)//if deleted elent is less then the median
                median_itr++;//the median goes forward (if the new size is even)
            else if((mySet.size()-1) %2 == 0 && temp_itr1 == median_itr)//deleting the median itself.
                    median_itr++;//the median goes forward (if the new size is even)
            else if((mySet.size()-1) %2 == 0 && val == *median_itr)
            {
                if(distance(temp_itr1,median_itr) >= 0)//deleting an element equal the median,
                //but is not the median
                    median_itr++;//median goes forward one step (if the new size is odd and deleted element 
                //position is before the median.)
            }            
             if(temp_itr1 == mySet.end())
                median_itr = temp_itr;
             else
                 mySet.erase(temp_itr1);   
        }
        if(!mySet.empty() && (temp_itr1 != mySet.end() || op == 'a')){
            if(mySet.size()%2 == 0 && mySet.size() > 0)
            {
                temp_itr = median_itr;
                temp_itr--;       
               // std::stringstream ss;
                //std::string str;
                //ss << std::fixed << (*temp_itr+*median_itr)/2.0; 
                //ss >> str;
                //str = TrimString(str);
             if((*temp_itr %2 == 0 && *median_itr %2 != 0)||(*median_itr%2 == 0 && *temp_itr %2 != 0))
             cout << fixed << setprecision(1) << (*temp_itr+*median_itr)/2.0 << endl;
             else 
                cout << (long int)((*temp_itr+*median_itr)/2.0) << endl;
        
            }else
                cout << *median_itr << endl;
        }else
            cout << "Wrong!" << endl;
        n--;
    }
    return 0;
}
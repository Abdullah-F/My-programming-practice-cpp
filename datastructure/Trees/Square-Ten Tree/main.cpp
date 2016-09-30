#include<iostream>
#include<map>
#include<vector>
#include <algorithm>
#include <sstream>
using namespace std;

#define subtract_letters(letter1,letter2)(char((letter1 - letter2)+48))
#define subtract_letters_with_bowrrow(letter1,letter2)\
 char(((letter1-48)+10 -(letter2-48))+48)
#define get_level(level)if(level == 0)level = 1;\
else level+= level;
inline void get_level_as_zeros(string &level_str) {
    if (level_str == "1") level_str = "0";
    else level_str += level_str;
}
inline void add_zeros(int length, string& str) {
    for (int i = 0; i < length; i++) str = "0" + str;
}
void replace(string& str, int left, int right) {
    for (int i = left; i < right && i < str.length(); i++) {
        str[i] = '0';
    }
}
inline string remove_leading_zeros(string result) {
    int i;
    for (i = 0; i < result.length(); i++)
        if (result[i] != '0') break;

    if (i == result.length())
        return "0";

    return result.substr(i);
}
string big_subtraction(string num1, string num2) {
    if (num1.length() == 0)
        return num2;
    else if (num2.length() == 0)
        return num1;
    else if (num1.length() == 0 && num2.length() == 0)
        return "0";

    int diff = abs(num1.length() - num2.length());

    if (num2.length() < num1.length())
        add_zeros(diff, num2);
    else if (num2.length() > num1.length())
        add_zeros(num2.length() - num1.length(), num1);

    if (num1 < num2)
        swap(num1, num2);

    bool borrow = false;
    string result = "";
    for (int i = num1.length() - 1; i > -1; i--) {
        if (borrow && num1[i] == '0')
            num1[i] = '9';
        else if (borrow) {
            num1[i] = (num1[i] - '1') + 48;
            borrow = false;
        }

        if (num1[i] >= num2[i])
            result = subtract_letters(num1[i], num2[i]) + result;
        else {
            result = subtract_letters_with_bowrrow(num1[i], num2[i]) + result;
            borrow = true;
        }
    }

    return remove_leading_zeros(result);
}

void add_one_to_big_number(string& big_number) {
    bool carry = true;
    for (int i = big_number.length() - 1; i > -1; i--) {
        if (big_number[i] < '9' && carry) {
            big_number[i] = big_number[i] + '1' - '0';
            carry = false;
            break;
        } else {
            big_number[i] = '0';
        }
    }

    if (carry)
        big_number = '1' + big_number;
}

string sub_str;
vector< pair<int,string> > get_ten_tree(string& left, string& right,int& number_of_levels) {
    vector< pair<int,string> > result;
    long long int level = 0, counter = 0;

    reverse(right.begin(), right.end());

    while (true) {
        if ((level + level) + 1 > right.length() && left != "1")
            break;

        if (level + 1 > right.length() && left == "1")
            break;

        if (level != 0) {
            sub_str = right.substr(level, level);
            sub_str = remove_leading_zeros(sub_str);
            if (sub_str != "0") {
                
                result.push_back(pair<int ,string>(counter,right.substr(level, level)));
                replace(right, level, 2 * level);
            }

        } else {
            sub_str = right.substr(0, level + 1);
            sub_str = remove_leading_zeros(sub_str);
            if (sub_str != "0") {
                    result.push_back(pair<int ,string>(counter,right.substr(0, level + 1)));
                    replace(right, 0, 1);
            }
        }
        get_level(level);
        counter++;
    }
    reverse(right.begin(), right.end());
    
    if (left != "1") {
        right = big_subtraction(right, left);
        add_one_to_big_number(right);
        reverse(result.begin(), result.end());
        left = "1";
        vector<pair<int,string>> result2 = get_ten_tree(left, right,number_of_levels);
        
        number_of_levels += result.size();
        cout <<  number_of_levels << endl;
        
        for(int i = 0 ; i < result2.size() ; i++){
            reverse(result2[i].second.begin(),result2[i].second.end());
            cout << result2[i].first << " " << result2[i].second << endl;
            
        }
        return result;
    }
    
    number_of_levels+= result.size();
    return result;
}

int main() {
    string left, right;
    cin >> left >> right;
    long long int level = 0;

    int number_of_levels = 0;
   vector<pair<int,string>> result2 = get_ten_tree(left, right,number_of_levels);
        
        
        for(int i = 0 ; i < result2.size() ; i++){
            reverse(result2[i].second.begin(),result2[i].second.end());
            cout << result2[i].first << " " << remove_leading_zeros(result2[i].second) << endl;
            
        }
   
    return 0;
}

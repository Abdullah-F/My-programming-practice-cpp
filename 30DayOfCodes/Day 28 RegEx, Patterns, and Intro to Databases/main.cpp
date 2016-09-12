#include <iostream>
#include <string>
#include <regex>
#include<map>

using namespace std;

int main() {
    string s;
    smatch m;
    regex e("(@gmail.com)"); // matches words beginning by "sub"
    string mail;
    multimap<string, string> DB_map;
    int n;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> s >> mail;
        DB_map.insert(pair<string, string>(s, mail));

    }

    map<string, string>::iterator itr = DB_map.begin();

    for (; itr != DB_map.end(); itr++)
        if (regex_search(itr->second, m, e))
            cout << itr->first << std::endl;

    return 0;
}
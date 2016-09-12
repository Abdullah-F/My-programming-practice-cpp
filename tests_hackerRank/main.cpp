#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include<sstream>
#include <map>
#include<stack>
using namespace std;

struct Test {
    Test()
    {
        has_parent =false;
    }
    map<string, string> tags_list;
    bool has_parent;

    string tagName;

    map<string, string> values;
};

#define noQutes(str) str.substr(1,str.length()-2)
#define getValuePair(read_value_name,read_value) pair<string,string>(read_value_name,read_value)
#define foreach(q) for(int i = 0 ; i < q ; i++)

int main() {

    int n, q;
    bool found = true;
    string HRML_line, readyToRead, read_value, read_value_name;
    map<string, Test*> full_HRML_source;
    stack<Test*> tags_sequencer;
    Test* temp;

    cin >> n >> q;

    cin.ignore();

    stringstream read(readyToRead);

    foreach(n) {
        getline(cin, HRML_line);

        if (!tags_sequencer.empty()) {
            if (("</" + tags_sequencer.top()->tagName + ">") == HRML_line) {
                full_HRML_source.insert(
                        pair< string, Test*>(tags_sequencer.top()->tagName, tags_sequencer.top()));
                tags_sequencer.pop();
                continue;
            }
        }
        readyToRead = noQutes(HRML_line);
        temp = new Test();


        read << readyToRead;

        read >> readyToRead;
        temp->tagName = readyToRead;


        if (!tags_sequencer.empty())
        {
            tags_sequencer.top()->tags_list.insert(
                pair<string, string>(readyToRead, readyToRead));
            temp->has_parent =true;
        }

        while (read >> read_value_name) {

            read >> readyToRead;


            read >> read_value;
            read_value = noQutes(read_value);

            temp->values.insert(getValuePair(read_value_name, read_value));

        }



        tags_sequencer.push(temp);
        read.clear();



    }
    
    
   
    

  
    map<string,Test*>::iterator itr = full_HRML_source.begin();
    map<string,string> ::iterator str_itr;
    
    string head_of_query = "";
    char input_letter;
    bool has_parent ,is_madd = false;
    
    
    
    
    for(int i = 0 ; i < q; i++)
    {
        getline(cin,HRML_line);
        
        
        istringstream ss(HRML_line);
        
        while (ss >> input_letter) {
            
            if(input_letter == '.' || input_letter == '~')
                break;
            head_of_query += input_letter;
        }
    
   
        itr = full_HRML_source.find(head_of_query);
        
        if(itr != full_HRML_source.end())
        if(itr->second->has_parent)
        {
            has_parent = true;
        }
        else has_parent = false;
        
        temp =NULL;
        istringstream kk(HRML_line);
        head_of_query = "";
        while(kk >> input_letter)
        {
            if(input_letter == '~')
            {
                is_madd =true;
            }
            
            if((input_letter == '.' || input_letter == '~') && temp == NULL)
            {
                itr = full_HRML_source.find(head_of_query);
                if(itr != full_HRML_source.end())
                    temp =itr->second;
                else 
                {
                    found =false;
                    break;
                }
                head_of_query = "";
            }else if(input_letter == '.' || input_letter == '~')
            {
                
                itr = full_HRML_source.find(head_of_query);
                if(itr != full_HRML_source.end())
                {
                    
                    str_itr = temp->tags_list.find(head_of_query);
                    if(str_itr != temp->tags_list.end())
                    {
                        temp =itr->second;
                    }else
                    {
                        found = false;
                        break;
                    }
                    
                }else{
                    found =false;
                    break;
                }
                head_of_query = "";
            }else head_of_query+=input_letter;
            
        }
        
        
        if(found && !has_parent && is_madd)
        {
            str_itr = temp->values.find(head_of_query);
            if(str_itr != temp->values.end())
            {
            cout << str_itr->second << endl;    
            }else{
            cout << "Not Found!" << endl;
        }
            
        }else{
            cout << "Not Found!" << endl;
        }
        
        has_parent =false;
        head_of_query = "";
        found =true;
        is_madd = false;
   
    } 
    return 0;
}

#include <iostream>
#include <stdlib.h>
#include<sstream>
using namespace std;
/*
int getNumberOfSpaces(string str)
{
    int counter ;
    
    for(int i = 0 ; i < str.length() ; i++)
        if(str[i] == ' ') counter++;
        
    return counter;
}
*/

int main() {
    int numberOfSequences , numberOfQueries ,counter;
    string input ,subString = "";
    
    cin >> numberOfSequences >> numberOfQueries;
    
    int sizes[numberOfSequences];
    
    int** sequences = new int*[numberOfSequences];
    int* array;
    int inp;
    cin.ignore();
    
    for(int i = 0 ; i < numberOfSequences ; i++)
    {
        getline(cin,input);
        counter =0;
        for(int jj = 0 ; jj < input.length() ; jj++)
        if(input[jj] == ' ') counter++;

        
        sizes[i] =counter+1;
        array = new int[sizes[i]];
        
        
        input =input+" ";
        
        for(int j = 0 , k= 0; j < input.length() ; j++)
        {
            if(input[j] != ' ')
            {
                subString += input[j];
            }else{
            
            array[k] = atoi(subString.c_str());
            k++;
            subString = "";
            
            }
            
           
            
            
        }
        
        sequences[i] = array;   
       
    
    }
    
    
    for(int i = 0,seqIndex,index ; i < numberOfQueries ; i++)
    {
      cin >> seqIndex >> index;
      cout << sequences[seqIndex][++index];
      cout << endl;
    }
    
    

	return 0;
}

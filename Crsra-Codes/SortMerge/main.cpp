#include <iostream>
#include <vector>
using namespace std;

template<class T>
vector<T> merge(vector<T> sorted1 , vector<T> sorted2)
{
    vector<T> merge_result;
    int sorted1_i = 0 , sorted2_i = 0;
    
    while (sorted1_i < sorted1.size() && sorted2_i < sorted2.size()) {
        if(sorted1[sorted1_i] <= sorted2[sorted2_i])
        {
            merge_result.push_back(sorted1[sorted1_i]);
            sorted1_i++;
        }else{
            merge_result.push_back(sorted2[sorted2_i]);
            sorted2_i++;
        }
    }
    
     while (sorted1_i < sorted1.size()) {
            merge_result.push_back(sorted1[sorted1_i]);
            sorted1_i++;
        }

        while (sorted2_i < sorted2.size()) {
            merge_result.push_back(sorted2[sorted2_i]);
            sorted2_i++;
        }
    
    return merge_result;
    
}

template<class T>
vector<T> sortMerge(vector<T> to_be_sorted_array , int lower,int upper)
{
    int size = upper-lower;
    
    if(upper == lower)
    {
       vector<T> oneElement(1,to_be_sorted_array[lower]);
        return oneElement;
    }

 vector<T> sorted1 = sortMerge(to_be_sorted_array ,lower , lower+(size/2));
 vector<T> sorted2 = sortMerge(to_be_sorted_array ,lower+((size/2)+1),upper);
 
 return merge(sorted1,sorted2);
 
}

int main() {
    vector<int> v1 , v2;
    int n1 ,n2 ;
    int in;
    cin >> n1;
    
    for(int i = 0 ; i < n1 ; i++)
    {
     cin >> in;
     v1.push_back(in);
    }
       
    vector<int> v3 = sortMerge(v1,0,v1.size()-1);
    
    for(int i = 0 ; i  < v3.size() ; i++)
    {
        cout << v3[i] << "  ";
    
    }
    cout << endl;
    
    
    return 0;
}


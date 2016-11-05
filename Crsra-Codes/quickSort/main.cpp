#include <iostream>
#include<vector>
#include <sstream>

using namespace std;

template<class T>
vector<int> partition(vector<T>& to_be_partitioned , int left,int right)
{
    int index = left+1;
    int mid = left;
    vector<int> mids(2,0);
    
    while (index <= right) {
        if(to_be_partitioned[index] <= to_be_partitioned[left])
        {         
            mid++;
            swap(to_be_partitioned[index],to_be_partitioned[mid]);
        }
        index++;
    }
    
    swap(to_be_partitioned[left],to_be_partitioned[mid]);
    mids[0] = mid;
    
    while (to_be_partitioned[mid] == to_be_partitioned[mids[0]]) mid--;
    mids[1] = mid;
    
    return mids;
}

template<class T>
void quikSort(vector<T>& to_be_partitioned , int left , int right)
{
    if(left >= right)
        return;
    
    int rand_number = ( rand() %(right-left+1))+left;
    swap(to_be_partitioned[rand_number],to_be_partitioned[left]);
    
    vector<int> mid = partition(to_be_partitioned,left,right);
    
    quikSort(to_be_partitioned,left,mid[1]);
    quikSort(to_be_partitioned,mid[0]+1,right);
}

int main() {

    vector<int> v1;
    
    int size , in;
    cin >> size;
    
    for(int i = 0 ; i < size ; i++) {
        cin >> in;
        v1.push_back(in);
    }
    
     quikSort(v1,0,v1.size()-1);
    
    
    for(int i = 0 ; i < v1.size() ; i++)
    {
        cout << v1[i] << " ";
    }
    
    cout << endl;

    return 0;
}
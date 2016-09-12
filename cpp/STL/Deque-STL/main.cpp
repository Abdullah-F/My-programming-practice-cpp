#include <iostream>
#include <deque>
#include <algorithm> 
using namespace std;
void printKMax(int arr[], int n, int k){
    deque<int> myDeck;//:)
    int i;
    for( i = 0 ; i < k ; ++i)
    {
        while(!myDeck.empty() && arr[i] >= arr[myDeck.back()])
            myDeck.pop_back();
        
        
        myDeck.push_back(i);
    }
    
    for(; i < n ; ++i)
    {
        cout << arr[myDeck.front()] << " ";
        
        while(!myDeck.empty() && myDeck.front() <= (i-k))
            myDeck.pop_front();
        
        while(!myDeck.empty() && arr[i] >= arr[myDeck.back()])
            myDeck.pop_back();
        
        myDeck.push_back(i);
        
    }
    
    cout << arr[myDeck.front()] << endl;
    
}
int main(){
  
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}

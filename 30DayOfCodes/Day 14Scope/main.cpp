#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
         
            int maximumDifference;
            Difference(vector<int> &a){
                
                for(int i = 0 ; i < a.size() ; i++)
                {	// Add your code hereDifference(vector<int> &a){
                
                for(int i = 0 ; i < a.size() ; i++)
                {
                    elements.push_back(a[i]);
                }
            }
  	
           
            
            void computeDifference(){
                maximumDifference = 0;
                for(int i = 0 ; i < elements.size()-1 ; i++)
                {
                    for(int j = i+1 ; j < elements.size() ; j++)
                    {
                     if(abs(elements[i]-elements[j]) > maximumDifference)
                         maximumDifference = abs(elements[i]-elements[j]);
                    }
                }
                
            }
        
                    elements.push_back(a[i]);
                }
            }
  	
           
            
            void computeDifference(){
                maximumDifference = 0;
                for(int i = 0 ; i < elements.size()-1 ; i++)
                {
                    for(int j = i+1 ; j < elements.size() ; j++)
                    {
                     if(abs(elements[i]-elements[j]) > maximumDifference)
                         maximumDifference = abs(elements[i]-elements[j]);
                    }
                }
                
            }
        
}; // End of Difference class

        
        
        
int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}
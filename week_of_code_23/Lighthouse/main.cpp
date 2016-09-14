#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size ;
     
    int left = 1 , right = 1 , top = 1 , bottom = 1 , tp_r = 1 , tp_l = 1 ,bt_l =1 ,bt_r=1;
    int lefti = 0 , righti = 0 , topi = 0 , bottomi = 0;
    int tri = 0 , trj = 0 , tli = 0 , tlj = 0,bli = 0 , blj = 0,bri = 0 , brj = 0;
    int answer = 0;
    cin >> size;
    
    char** input_grid = new char*[size];
    
    for(int i=0 ; i < size ; i++)
    {
        input_grid[i] = new char[size];
    }
    
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ;j++)
        cin >> input_grid[i][j];
    }
    
    for(int i = 1 ; i < size-1  ; i++)
    {
        for(int j = 1 ; j < size-1 ; j++)
        {
            if(input_grid[i][j] == '.')
            {
                lefti = j-1;
                righti = j+1;
                while(lefti > -1)
                {
                    if(input_grid[i][lefti] == '.')
                    {
                        left++;
                    }else break;
                    lefti--;
                }
                
                while(righti < size){
                    if(input_grid[i][righti] == '.')
                    {
                        right++;
                    }else break;
                    righti++;
                }
                
                topi = i-1;
                bottomi = i+1;
                
                while(topi > -1)
                {
                    if(input_grid[topi][j] == '.')
                    {
                        top++;
                    }else break;
                    topi--;
                }
                while(bottomi < size)
                {
                    if(input_grid[bottomi][j] == '.')
                    {
                        bottom++;
                    }else break;
                    bottomi++;
                }
                
                tri = i-1;
                trj = j+1;
                
                while(tri  > -1 &&  trj < size )
                {
                    if(input_grid[tri][trj] == '.')
                    {
                        tp_r++;
                    }else break;
                    tri--;
                    trj++;
                }
                
                
                tli = i-1;
                tlj = j-1;
                
                while(tli  > -1 &&  tlj > -1 )
                {
                    if(input_grid[tli][tlj] == '.')
                    {
                        tp_l++;
                    }else break;
                    tli--;
                    tlj--;
                }
                bli = i+1;
                blj = j-1;
                while(bli  < size &&  blj > -1 )
                {
                    if(input_grid[bli][blj] == '.')
                    {
                        bt_l++;
                    }else break;
                    bli++;
                    blj--;
                }
                
                
                bri = i+1;
                brj = j+1;
                while(bri  < size &&  brj < size )
                {
                    if(input_grid[bri][brj] == '.')
                    {
                        bt_r++;
                    }else break;
                    bri++;
                    brj++;
                }
                
             
        }
            
               if(top < 2 || bottom < 2 || right < 2 || left < 2 || tp_r < 2 || tp_l < 2 || bt_l < 2 || bt_r< 2)
            {
                top = bottom =left =right = tp_r = tp_l  = bt_l=bt_r =0;
            }
            else{
                int maxi = max(max(max(max(max(max(top,bottom),max(left,right)),tp_r),tp_l),bt_l),bt_r);
             
                if(maxi >= answer)
                {
                    answer = maxi;
                }
                top = bottom =left =right = tp_r = tp_l = bt_l = bt_r = 0;
            }
                
            }
            
            
    }
    
    
    cout << answer << endl;
        
    return 0;
}

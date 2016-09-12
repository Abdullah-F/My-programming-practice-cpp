#include<bits/stdc++.h>
#include<map>
using namespace std;

struct Workshop {
    int duration;
    int start_time;
    bool flag ;

    Workshop(int st , int dur) {
        duration = dur;
        start_time = st;
        flag = false;
    }
};

struct Available_Workshops {
    int n;
    multimap<int, Workshop*> work_shops;


};

Available_Workshops* initialize(int* start_time, int* duration, int n) {
    Available_Workshops* av_wr_shops = new Available_Workshops;

    av_wr_shops->n = n;

    for (int i = 0; i < n; i++) {
        av_wr_shops->work_shops.insert(pair<int, Workshop*>(start_time[i]+duration[i], new Workshop(
                start_time[i] ,duration[i])));
    }

    return av_wr_shops;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
     multimap<int, Workshop*>::iterator itr = ptr->work_shops.begin() , itr1;
     int max =0;
    for( ; itr != ptr->work_shops.end() ; )
    {
     
        for(itr1 = ++itr , --itr; itr1 != ptr->work_shops.end() ;)
        {
          if(itr->first > itr1->second->start_time )
          {  
              cout << itr1->first << " " << itr1->second->start_time << "  deleted" << endl;
              itr1 = ptr->work_shops.erase(itr1);
          }else itr1++;
          
        }
        
         max++;
          cout << itr->first << " " << itr->second->start_time << "  deleted" << endl;
          itr = ptr->work_shops.erase(itr);
         
        
    }
     
    return max;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}

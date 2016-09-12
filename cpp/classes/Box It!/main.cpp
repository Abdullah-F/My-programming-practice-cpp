#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stl_tempbuf.h>
#include <iosfwd>

using namespace std;

int BoxesCreated, BoxesDestroyed;

class Box {
public:

    Box() {
        l = b = h = 0;
        BoxesCreated++;
    }

    Box(int length, int breadth, int height) {
        l = length;
        b = breadth;
        h = height;
        BoxesCreated++;
    }

    Box(Box& box) {
        b = box.b;
        h = box.h;
        l = box.l;
        BoxesCreated++;
    }

    int getLength()
    {
        return l;
    }
    
    int getBreadth()
    {
        return b;
    }
    int getHeight()
    {
        return h;
    }
    
    long long int CalculateVolume()
    {
        return l * b * h;
    }
    
    bool operator<(Box box)
    {
        if(l < box.l)
            return true;
        else if(b < box.b && l == box.l)
            return true;
        else if(h < box.h && b == box.b && l==box.l)
            return true;
        return false;
    }
    
  
    
    ~Box() {
        BoxesDestroyed++;
    }




private:
    int l;
    int b;
    int h;
};


  ostream& operator<<(ostream& os , Box box)
    {
        cout << box.getLength() << " " << box.getBreadth() << " " << box.getHeight() ;
        return os;
    }
  
void check2() {
    int n;
    cin>>n;
    Box temp;
    for (int i = 0; i < n; i++) {
        int type;
        cin>>type;
        if (type == 1) {
            cout << temp << endl;
        }
        if (type == 2) {
            int l, b, h;
            cin >> l >> b>>h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3) {
            int l, b, h;
            cin >> l >> b>>h;
            Box NewBox(l, b, h);
            if (NewBox < temp) {
                cout << "Lesser" << endl;
            } else {
                cout << "Greater" << endl;
            }
        }
        if (type == 4) {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5) {
            Box NewBox(temp);
            cout << NewBox << endl;
        }

    }
}

int main() {
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout << "Boxes Created : " << BoxesCreated << endl << "Boxes Destroyed : " << BoxesDestroyed << endl;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Person{
    
public:
    
    Person()
    {
        name= "";
        age =0;
    }
    virtual void getdata(){};
    virtual void putdata(){};
    
    void setAge(int age){
        this->age = age;
    }
    
class Person{
    
public:
    
    Person()
    {
        name= "";
        age =0;
    }
    virtual void getdata(){};
    virtual void putdata(){};
    
    void setAge(int age){
        this->age = age;
    }
    
    int getAge()
    {
        return age;
    }
    
    void setName(string name)
    {
        this->name = name;
    }
    
    string getName()
    {
        return name;
    }

private:
    string name;
    int age;
     
};

class Student:public Person{

public:
    Student()
    {
        total = 0 ;
        _id = ++id;
    }
    
    static int id;
   
     void getdata()
    {
        string name;
        cin >> name;
  
        int age;
        cin >> age;
        
        
        setName(name);
        setAge(age);
        
        for(int i = 0 ; i< 6 ; i++)
        {
            cin >> marks[i];
            
            total+=marks[i];
        }
        
        
        
    }
    

     void putdata(){
        cout << getName() << " " << getAge() << " " << total <<" " << _id << endl;
    }


private:
    int marks[6];
    int total;
    int _id;
    
    
};


class Professor:public Person{
    
public:
    Professor()
    {
        _id = ++id;
    }

    void getdata()
    {
     string name;
        cin >> name;
  
        int age;
        cin >> age;
        
        
        setName(name);
        setAge(age);
        
        cin >> age;
        publicantsNumber =age;
        
    
    }
    

    virtual void putdata(){
        cout << getName() << " " << getAge() <<" "<< publicantsNumber <<" " << _id << endl;
    }
    
    static int id;
    
private:
    int publicantsNumber;
    int _id;


    
};

int Student::id =0;
int Professor::id =0;
    int getAge()
    {
        return age;
    }
    
    void setName(string name)
    {
        this->name = name;
    }
    
    string getName()
    {
        return name;
    }

private:
    string name;
    int age;
     
};

class Student:public Person{

public:
    Student()
    {
        total = 0 ;
        _id = ++id;
    }
    
    static int id;
   
     void getdata()
    {
        string name;
        cin >> name;
  
        int age;
        cin >> age;
        
        
        setName(name);
        setAge(age);
        
        for(int i = 0 ; i< 6 ; i++)
        {
            cin >> marks[i];
            
            total+=marks[i];
        }
        
        
        
    }
    

     void putdata(){
        cout << getName() << " " << getAge() << " " << total <<" " << _id << endl;
    }


private:
    int marks[6];
    int total;
    int _id;
    
    
};


class Professor:public Person{
    
public:
    Professor()
    {
        _id = ++id;
    }

    void getdata()
    {
     string name;
        cin >> name;
  
        int age;
        cin >> age;
        
        
        setName(name);
        setAge(age);
        
        cin >> age;
        publicantsNumber =age;
        
    
    }
    

    virtual void putdata(){
        cout << getName() << " " << getAge() <<" "<< publicantsNumber <<" " << _id << endl;
    }
    
    static int id;
    
private:
    int publicantsNumber;
    int _id;


    
};

int Student::id =0;
int Professor::id =0;
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

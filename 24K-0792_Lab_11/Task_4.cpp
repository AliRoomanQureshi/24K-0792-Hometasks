#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    int roll;
    string name;
    bool occupied;
    Student(){ roll=-1; name=""; occupied=false; }
};

class StudentHashTable{
private:
    static const int SIZE=15;
    Student table[SIZE];
public:
    int hashFunction(int roll){ return roll%SIZE; }

    void InsertRecord(int roll,string name){
        int index=hashFunction(roll);
        for(int attempt=0; attempt<SIZE; attempt++){
            int newIndex=(index+attempt*attempt)%SIZE;
            if(!table[newIndex].occupied){
                table[newIndex].roll=roll;
                table[newIndex].name=name;
                table[newIndex].occupied=true;
                cout<<"Record inserted at index "<<newIndex<<endl;
                return;
            }
        }
        cout<<"Error: Hash table full"<<endl;
    }

    void SearchRecord(int roll){
        int index=hashFunction(roll);
        for(int attempt=0; attempt<SIZE; attempt++){
            int newIndex=(index+attempt*attempt)%SIZE;
            if(table[newIndex].occupied && table[newIndex].roll==roll){
                cout<<"Record found! Name: "<<table[newIndex].name<<endl;
                return;
            }
        }
        cout<<"Record not found"<<endl;
    }
};

int main(){
    StudentHashTable ht;
    ht.InsertRecord(101,"Ali");
    ht.InsertRecord(116,"Sara");
    ht.InsertRecord(131,"John");

    cout<<"Searching 116:"<<endl;
    ht.SearchRecord(116);

    cout<<"Searching 200:"<<endl;
    ht.SearchRecord(200);

    return 0;
}

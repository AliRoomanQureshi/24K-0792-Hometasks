#include <iostream>
#include <string>
using namespace std;

class HashTable{
private:
    string table[50];
    int size=50;

    int asciiSum(const string& name){
        int sum=0;
        for(char c:name) sum+=int(c);
        return sum;
    }

public:
    void Add_Employee(string name){
        int sum=asciiSum(name);
        int h1=sum%size;
        int h2=7-(sum%7);

        if(table[h1]==""){
            table[h1]=name;
            return;
        }

        for(int i=1;i<size;i++){
            int newIndex=(h1+i*h2)%size;
            if(table[newIndex]==""){
                table[newIndex]=name;
                return;
            }
        }

        cout<<"Table is full. Unable to insert \""<<name<<"\"."<<endl;
    }

    void Search_Employee(string name){
        int sum=asciiSum(name);
        int h1=sum%size;
        int h2=7-(sum%7);

        if(table[h1]==name){
            cout<<"\""<<name<<"\" found at index "<<h1<<endl;
            return;
        }

        for(int i=1;i<size;i++){
            int newIndex=(h1+i*h2)%size;
            if(table[newIndex]==name){
                cout<<"\""<<name<<"\" found at index "<<newIndex<<endl;
                return;
            }
            if(table[newIndex]=="") break;
        }

        cout<<"Employee not found in the directory."<<endl;
    }

    void Display_Table(){
        cout<<"\n--- Employee Hash Table (Double Hashing) ---"<<endl;
        for(int i=0;i<size;i++){
            if(table[i]!="") cout<<i<<" --> "<<table[i]<<endl;
        }
        cout<<"-------------------------------------------"<<endl;
    }
};

int main(){
    HashTable HT;

    HT.Add_Employee("Zainab Rajput");
    HT.Add_Employee("Ali");
    HT.Add_Employee("Ayesha");
    HT.Add_Employee("Usman");

    HT.Display_Table();

    HT.Search_Employee("Ayesha");
    HT.Search_Employee("Hamza");

    return 0;
}

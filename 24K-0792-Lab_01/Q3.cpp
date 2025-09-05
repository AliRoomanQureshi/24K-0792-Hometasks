#include <iostream>
using namespace std;

class Exam {
private:
    int* marks;
public:
    Exam(int m) {
        marks = new int(m);
    }

    ~Exam() {
        delete marks;
    }

    void setMarks(int m) {
        *marks = m;
    }

    int getMarks() const {	
        return *marks;
    }
};

int main() {
    Exam e1(90);
    cout<<"Exam1 Marks: "<<e1.getMarks()<<endl;
    Exam e2 = e1;
    cout<<"Exam2 (copy of Exam1) Marks: "<<e2.getMarks()<<endl;
    e2.setMarks(50);
    cout<<"\nAfter changing Exam2:"<<endl;
    cout<<"Exam2 Marks: "<<e2.getMarks()<<endl;
    cout<<"Exam1 Marks: "<<e1.getMarks()<<" also changed due to shallow copy"<<endl;
    return 0;
}
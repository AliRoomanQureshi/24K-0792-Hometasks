#include <iostream>
#include <string>
using namespace std;

class ResearchPaper {
private:
    string* authors;
    int authorCount;

public:
    ResearchPaper(int count, string* names) {
        authorCount = count;
        authors = new string[authorCount];
        for (int i = 0; i < authorCount; i++) {
            authors[i] = names[i];
        }
    }

    ResearchPaper(const ResearchPaper& other) {
        authorCount = other.authorCount;
        authors = new string[authorCount];
        for (int i = 0; i < authorCount; i++) {
            authors[i] = other.authors[i];
        }
    }

    ResearchPaper& operator=(const ResearchPaper& other) {
        if (this != &other) {
            delete[] authors;
            authorCount = other.authorCount;
            authors = new string[authorCount];
            for (int i = 0; i < authorCount; i++) {
                authors[i] = other.authors[i];
            }
        }
        return *this;
    }

    ~ResearchPaper() {
        delete[] authors;
    }

    void display() const {
        cout << "Authors: ";
        for (int i = 0; i < authorCount; i++) {
            cout << authors[i];
            if (i < authorCount - 1) cout << ", ";
        }
        cout << endl;
    }

    void setAuthor(int index, const string& newName) {
        if (index >= 0 && index < authorCount) {
            authors[index] = newName;
        }
    }
};

int main() {
    string authors1[] = {"Ali", "Rooman", "Shayan"};
    ResearchPaper paper1(3, authors1);

    cout << "Original Paper1:" << endl;
    paper1.display();

    ResearchPaper paper2 = paper1;
    cout << "\nPaper2 (copy of Paper1):" << endl;
    paper2.display();

    paper2.setAuthor(1, "Muzammil");

    cout << "\nAfter modifying Paper2:" << endl;
    paper2.display();

    cout << "Paper1 remains unchanged:" << endl;
    paper1.display();

    string authors3[] = {"Ahmed", "Sara"};
    ResearchPaper paper3(2, authors3);
    cout << "\nBefore assignment, Paper3:" << endl;
    paper3.display();

    paper3 = paper1;
    cout << "\nAfter assignment, Paper3:" << endl;
    paper3.display();

    return 0;
}

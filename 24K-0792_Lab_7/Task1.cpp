#include <iostream>
#include <string>
using namespace std;

class StudentNode {
public:
    string name;
    int score;
    StudentNode* next;
    StudentNode(string n, int s) {
        name = n;
        score = s;
        next = nullptr;
    }
};

void insert(StudentNode** headRef, string name, int score) {
    StudentNode* newNode = new StudentNode(name, score);
    if (*headRef == nullptr) {
        *headRef = newNode;
        return;
    }
    StudentNode* temp = *headRef;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int getMaxScore(StudentNode* head) {
    int maxScore = 0;
    StudentNode* temp = head;
    while (temp != nullptr) {
        if (temp->score > maxScore) {
            maxScore = temp->score;
        }
        temp = temp->next;
    }
    return maxScore;
}

void radixSort(StudentNode** headRef) {
    if (*headRef == nullptr) return;
    int maxScore = getMaxScore(*headRef);

    for (int exp = 1; maxScore / exp > 0; exp *= 10) {
        StudentNode* bucketHeads[10] = {nullptr};
        StudentNode* bucketTails[10] = {nullptr};
        StudentNode* current = *headRef;

        while (current != nullptr) {
            int digit = (current->score / exp) % 10;
            StudentNode* nextNode = current->next;
            current->next = nullptr;

            if (bucketHeads[digit] == nullptr) {
                bucketHeads[digit] = current;
                bucketTails[digit] = current;
            } else {
                bucketTails[digit]->next = current;
                bucketTails[digit] = current;
            }
            current = nextNode;
        }

        *headRef = nullptr;
        StudentNode* lastNode = nullptr;

        for (int i = 0; i < 10; i++) {
            if (bucketHeads[i] != nullptr) {
                if (*headRef == nullptr) {
                    *headRef = bucketHeads[i];
                } else {
                    lastNode->next = bucketHeads[i];
                }
                lastNode = bucketTails[i];
            }
        }
    }
}

void display(StudentNode* head) {
    cout<<"\nSorted Student Records:\n";
    cout<<"Name\tScore\n";
    StudentNode* temp = head;
    while (temp != nullptr) {
        cout<<temp->name<<"\t"<<temp->score<<endl;
        temp = temp->next;
    }
}

void deleteList(StudentNode* head) {
    StudentNode* current = head;
    while (current != nullptr) {
        StudentNode* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    StudentNode* head = nullptr;
    int numStudents;

    cout<<"Enter number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        string name;
        int score;
        cout<<"Enter name of student "<<(i + 1)<<": ";
        cin >> name;
        cout<<"Enter score (00100): ";
        cin >> score;
        insert(&head, name, score);
    }

    cout<<"\nStarting student scores using Radix Sort...\n";
    radixSort(&head);
    display(head);
    deleteList(head);

    cout<<"\nPress any key to continue . . . ";
    cin.ignore();
    cin.get();
    return 0;
}

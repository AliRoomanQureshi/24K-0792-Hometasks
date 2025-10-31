#include <iostream>
using namespace std;

class EmployeeNode {
public:
    int id;
    EmployeeNode* leftChild;
    EmployeeNode* rightChild;

    EmployeeNode(int empID) {
        id = empID;
        leftChild = rightChild = nullptr;
    }
};

class HierarchyTree {
private:
    EmployeeNode* root;

    EmployeeNode* insertNode(EmployeeNode* current, int id) {
        if (current == nullptr)
            return new EmployeeNode(id);

        if (id < current->id)
            current->leftChild = insertNode(current->leftChild, id);
        else if (id > current->id)
            current->rightChild = insertNode(current->rightChild, id);

        return current;
    }

    EmployeeNode* lowestCommon(EmployeeNode* current, int id1, int id2) {
        if (!current) return nullptr;

        if (id1 < current->id && id2 < current->id)
            return lowestCommon(current->leftChild, id1, id2);

        if (id1 > current->id && id2 > current->id)
            return lowestCommon(current->rightChild, id1, id2);

        return current;
    }

    void inorderTraversal(EmployeeNode* current) {
        if (!current) return;
        inorderTraversal(current->leftChild);
        cout<<current->id<<" ";
        inorderTraversal(current->rightChild);
    }

public:
    HierarchyTree() {
        root = nullptr;
    }

    void addEmployee(int id) {
        root = insertNode(root, id);
    }

    void showEmployees() {
        if (!root)
            cout<<"No employees in the system.\n";
        else {
            cout<<"\nEmployee IDs (Inorder Traversal): ";
            inorderTraversal(root);
            cout<<endl;
        }
    }

    void commonManager(int id1, int id2) {
        if (!root) {
            cout<<"Tree is empty.\n";
            return;
        }

        EmployeeNode* lca = lowestCommon(root, id1, id2);
        if (lca)
            cout<<"Lowest Common Manager for "<<id1<<" and "<<id2
                <<" is: "<<lca->id<<endl;
        else
            cout<<"One or both employee IDs not found.\n";
    }
};

int main() {
    HierarchyTree organization;
    int option, empID, e1, e2;

    while (true) {
        cout<<"\n=== EMPLOYEE MANAGEMENT SYSTEM ===\n";
        cout<<"1. Add Employee\n";
        cout<<"2. Display Employee Hierarchy\n";
        cout<<"3. Find Lowest Common Manager\n";
        cout<<"4. Exit\n";
        cout<<"Select an option: ";
        cin>>option;

        switch (option) {
            case 1:
                cout<<"Enter Employee ID: ";
                cin>>empID;
                organization.addEmployee(empID);
                break;

            case 2:
                organization.showEmployees();
                break;

            case 3:
                cout<<"Enter two Employee IDs: ";
                cin>>e1>>e2;
                organization.commonManager(e1, e2);
                break;

            case 4:
                cout<<"Exiting program...\n";
                return 0;

            default:
                cout<<"Invalid option! Please try again.\n";
        }
    }
}

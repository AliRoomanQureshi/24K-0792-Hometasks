#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int ticketID;
    string customerName;
    string rideName;
    Node* next;

    Node(int id, string cName, string rName) {
        ticketID = id;
        customerName = cName;
        rideName = rName;
        next = NULL;
    }
};

class TicketSystem {
private:
    Node* head;
    Node* tail;

public:
    TicketSystem() {
        head = tail = NULL;
    }

    void issueEnd(int id, string customer, string ride) {
        Node* newNode = new Node(id, customer, ride);
        if (head == NULL) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        cout << "Ticket issued (End): " << customer << " for " << ride << endl;
    }

    void issueFront(int id, string customer, string ride) {
        Node* newNode = new Node(id, customer, ride);
        if (head == NULL) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        cout << "Priority Ticket issued (Front): " << customer << " for " << ride << endl;
    }

    void cancelByID(int id) {
        if (head == NULL) {
            cout << "No tickets to cancel!\n";
            return;
        }
        Node* curr = head;
        Node* prev = tail;
        do {
            if (curr->ticketID == id) {
                if (curr == head && curr == tail) {
                    head = tail = NULL;
                } else if (curr == head) {
                    head = head->next;
                    tail->next = head;
                } else if (curr == tail) {
                    tail = prev;
                    tail->next = head;
                } else {
                    prev->next = curr->next;
                }
                cout << "Ticket ID " << id << " cancelled.\n";
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        cout << "Ticket ID " << id << " not found!\n";
    }

    void cancelFirst() {
        if (head == NULL) {
            cout << "No tickets to cancel!\n";
            return;
        }
        cancelByID(head->ticketID);
    }

    void searchTicket(int id) {
        if (head == NULL) {
            cout << "No tickets available.\n";
            return;
        }
        Node* curr = head;
        do {
            if (curr->ticketID == id) {
                cout << "Ticket Found: ID=" << curr->ticketID
                     << ", Customer=" << curr->customerName
                     << ", Ride=" << curr->rideName << endl;
                return;
            }
            curr = curr->next;
        } while (curr != head);
        cout << "Ticket ID " << id << " not found!\n";
    }

    void displayTickets() {
        if (head == NULL) {
            cout << "No tickets booked.\n";
            return;
        }
        cout << "\nAll Tickets (Circular Order):\n";
        Node* curr = head;
        do {
            cout << "ID=" << curr->ticketID
                 << ", Customer=" << curr->customerName
                 << ", Ride=" << curr->rideName << endl;
            curr = curr->next;
        } while (curr != head);
    }

    int countTickets() {
        if (head == NULL) return 0;
        int count = 0;
        Node* curr = head;
        do {
            count++;
            curr = curr->next;
        } while (curr != head);
        return count;
    }

    void nextTicket(int id) {
        if (head == NULL) {
            cout << "No tickets available.\n";
            return;
        }
        Node* curr = head;
        do {
            if (curr->ticketID == id) {
                Node* nextNode = curr->next;
                cout << "Next Ticket After ID " << id << ": "
                     << "ID=" << nextNode->ticketID
                     << ", Customer=" << nextNode->customerName
                     << ", Ride=" << nextNode->rideName << endl;
                return;
            }
            curr = curr->next;
        } while (curr != head);
        cout << "Ticket ID " << id << " not found!\n";
    }
};

int main() {
    TicketSystem system;
    system.issueEnd(1, "Ali", "Roller Coaster");
    system.issueEnd(2, "Sara", "Ferris Wheel");
    system.issueEnd(3, "Omar", "Bumper Cars");
    system.issueFront(0, "VIP-Zara", "Haunted House");
    system.displayTickets();
    system.cancelByID(2);
    system.displayTickets();
    system.cancelFirst();
    system.displayTickets();
    system.searchTicket(3);
    system.searchTicket(5);
    system.nextTicket(1);
    cout << "\nTotal Tickets: " << system.countTickets() << endl;
    return 0;
}

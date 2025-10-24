#include <iostream>
using namespace std;

class Node {
	public:
	    int data;
	    Node* next;
	    Node(int d) {
	        data = d;
	        next = NULL;
	    }
};

	void printList(Node* head) {
 	   while (head != NULL) {
  	      cout << head->data << " ";
  	      head = head->next;
 	   }
  	  cout << endl;
}

	Node* getTail(Node* cur) {
	    while (cur != NULL && cur->next != NULL)
	        cur = cur->next;
	    return cur;
	}

	Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
	    Node* pivot = end;
	    Node *prev = NULL, *cur = head, *tail = pivot;
	
	    while (cur != pivot) {
	        if (cur->data < pivot->data) {
	            if ((*newHead) == NULL)
	                *newHead = cur;
	            prev = cur;
	            cur = cur->next;
	        } else {
	            if (prev)
	                prev->next = cur->next;
	            Node* tmp = cur->next;
	            cur->next = NULL;
	            tail->next = cur;
	            tail = cur;
	            cur = tmp;
	        }
	    }
	
	    if ((*newHead) == NULL)
	        *newHead = pivot;
	
	    *newEnd = tail;
	    return pivot;
	}

	Node* quickSortRecur(Node* head, Node* end) {
	    if (!head || head == end)
	        return head;
	
	    Node *newHead = NULL, *newEnd = NULL;
	
	    Node* pivot = partition(head, end, &newHead, &newEnd);
	
	    if (newHead != pivot) {
	        Node* tmp = newHead;
	        while (tmp->next != pivot)
	            tmp = tmp->next;
	        tmp->next = NULL;
	
	        newHead = quickSortRecur(newHead, tmp);
	
	        tmp = getTail(newHead);
	        tmp->next = pivot;
	    }
	
	    pivot->next = quickSortRecur(pivot->next, newEnd);
	
	    return newHead;
	}

	void quickSort(Node** headRef) {
	    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
	}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    cout << "Original List: ";
    printList(head);

    quickSort(&head);

    cout << "Sorted List:   ";
    printList(head);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char arr[100];
    int topIndex;
public:
    Stack() { topIndex = -1; }
    bool empty() { return topIndex == -1; }
    void push(char c) { arr[++topIndex] = c; }
    char pop() { return empty() ? '\0' : arr[topIndex--]; }
    char top() { return empty() ? '\0' : arr[topIndex]; }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(const string& infix) {
    Stack s;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.pop();
            }
            s.pop(); // remove '('
        }
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                if (c == '^' && s.top() == '^') break; // right-associative
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout<<"Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout<<"Postfix Expression: "<<postfix<<endl;

    return 0;
}

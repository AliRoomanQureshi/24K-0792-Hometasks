#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class Stack {
private:
    int arr[MAX];
    int topIndex;
public:
    Stack() { topIndex = -1; }
    bool empty() { return topIndex == -1; }
    bool full() { return topIndex == MAX - 1; }
    void push(int value) {
        if (full()) return;
        arr[++topIndex] = value;
    }
    int pop() {
        if (empty()) return 0;
        return arr[topIndex--];
    }
    int top() {
        if (empty()) return 0;
        return arr[topIndex];
    }
};

int evaluatePostfix(const string& expr) {
    Stack s;
    for (char ch : expr) {
        if (ch >= '0' && ch <= '9') s.push(ch - '0');
        else {
            int val2 = s.pop();
            int val1 = s.pop();
            int result = 0;
            switch (ch) {
                case '+': result = val1+val2; break;
                case '-': result = val1-val2; break;
                case '*': result = val1*val2; break;
                case '/': if (val2 != 0) result = val1/val2; else return 0; break;
                default: return 0;
            }
            s.push(result);
        }
    }
    if (s.empty()) return 0;
    int finalResult = s.top();
    s.pop();
    if (!s.empty()) return 0;
    return finalResult;
}

int main() {
    string expression;
    cout<<"Enter postfix expression: ";
    cin >> expression;
    int result = evaluatePostfix(expression);
    cout<<"Final Result: "<<result<<endl;
    return 0;
}

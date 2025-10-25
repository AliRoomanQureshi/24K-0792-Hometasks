#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Stack {
private:
    int arr[100];
    int topIndex;
public:
    Stack() { topIndex = -1; }
    bool empty() { return topIndex == -1; }
    void push(int value) { arr[++topIndex] = value; }
    int pop() { return empty() ? 0 : arr[topIndex--]; }
    int top() { return empty() ? 0 : arr[topIndex]; }
};

int evaluatePrefix(const string& expr) {
    Stack s;
    for (int i = expr.length() - 1; i >= 0; i--) {
        char ch = expr[i];
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int val1 = s.pop();
            int val2 = s.pop();
            int result = 0;
            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': 
                    if (val2 == 0) {
                        cout<<"Error: Division by zero!\n";
                        return 0;
                    }
                    result = val1 / val2; 
                    break;
                case '^': result = pow(val1, val2); break;
                default: 
                    cout<<"Invalid operator: "<<ch<<endl; 
                    return 0;
            }
            s.push(result);
        }
    }
    return s.top();
}

int main() {
    string expression;
    cout<<"Enter prefix expression: ";
    cin >> expression;

    int result = evaluatePrefix(expression);
    cout<<"Final Result: "<<result<<endl;

    return 0;
}

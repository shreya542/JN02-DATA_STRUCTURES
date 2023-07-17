#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int getPrecedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(const string& infix) {
    stack<char> operatorStack;
    string prefixExpression;

    for (int i = infix.length() - 1; i >= 0; i--) {
        char ch = infix[i];

        if (isalnum(ch)) {
            prefixExpression = ch + prefixExpression;
        } else if (ch == ')') {
            operatorStack.push(ch);
        } else if (ch == '(') {
            while (!operatorStack.empty() && operatorStack.top() != ')') {
                prefixExpression = operatorStack.top() + prefixExpression;
                operatorStack.pop();
            }
            if (!operatorStack.empty())
                operatorStack.pop();
        } else if (isOperator(ch)) {
            while (!operatorStack.empty() && operatorStack.top() != ')' && getPrecedence(ch) <= getPrecedence(operatorStack.top())) {
                prefixExpression = operatorStack.top() + prefixExpression;
                operatorStack.pop();
            }
            operatorStack.push(ch);
        }
    }

    while (!operatorStack.empty()) {
        prefixExpression = operatorStack.top() + prefixExpression;
        operatorStack.pop();
    }

    return prefixExpression;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    string prefixExpression = infixToPrefix(infixExpression);

    cout << "Prefix expression: " << prefixExpression << endl;

    return 0;
}

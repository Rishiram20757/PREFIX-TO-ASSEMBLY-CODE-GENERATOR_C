#include <iostream>
#include <stack>
#include <cctype> // For isdigit() using
namespace std;

bool isOperator(char c) {
return (c == '+' || c == '-' || c == '*' || c == '/');
}

string prefixToPostfix(const string& prefix) {
stack<string> s;

for (int i = prefix.length() - 1; i >= 0; --i) {
char current = prefix[i];

if (isOperator(current)) {
// Pop two operands from the stack
string operand1 = s.top();
s.pop(); string
operand2 = s.top();
s.pop();

// Concatenate the operands with the operator and push back onto the stack
string result = operand1 + operand2 + current;
s.push(result);
} else if (isdigit(current)) {

14

// If the current character is a digit, push it onto the stack
s.push(string(1, current));
} else {
// Handle other characters if needed cerr << "Invalid character in
the prefix expression: " << current << endl; exit(EXIT_FAILURE);
}
}

// The final result is on the top of the stack return
s.top();
}

int main() { string
prefixExpression;

// Input the prefix expression cout
<< "Enter the prefix expression: "; cin
>> prefixExpression;

// Convert to postfix and display the result string
postfixExpression = prefixToPostfix(prefixExpression); cout
<< "Postfix expression: " << postfixExpression << endl;

return 0;
}
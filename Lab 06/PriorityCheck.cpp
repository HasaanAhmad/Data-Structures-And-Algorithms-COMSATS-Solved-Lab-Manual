#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Using Builtin Stack to avoid complexity for this Program
bool checkBracketPriority(string expression) {
    stack<char> bracketStack;
    for (char c : expression) {
        if (c == '(') {
            // Parenthesis cannot have any other type of bracket inside
            if (!bracketStack.empty() && bracketStack.top() != '(') {
                return false;
            }
            bracketStack.push(c);
        } else if (c == '[' || c == '{') {
            bracketStack.push(c);
        } else if (c == ')' && (!bracketStack.empty() && bracketStack.top() == '(')) {
            bracketStack.pop();
        } else if (c == ']' && (!bracketStack.empty() && bracketStack.top() == '[')) {
            bracketStack.pop();
        } else if (c == '}' && (!bracketStack.empty() && bracketStack.top() == '{')) {
            // Curly brackets can only contain more curly brackets or parentheses
            if (bracketStack.size() >= 2 && bracketStack.top() == '(' && bracketStack.top() == '(') {
                bracketStack.pop(); // remove the innermost parenthesis
                bracketStack.pop(); // remove the outermost curly bracket
            } else if (bracketStack.top() == '{') {
                bracketStack.pop();
            } else {
                return false;
            }
        } else {
            return false; // invalid bracket
        }
    }
    return bracketStack.empty(); // true if all brackets are closed and balanced
};

int main() {
    string expression = "({[]})";
    if (checkBracketPriority(expression)) {
        cout << "Prioritized" << endl;
    } else {
        cout << "Not Prioritized" << endl;
    } 
    if(checkBracketPriority("({[]})"))
        cout << "Prioritized" << endl;
    else
        cout << "Not Prioritized" << endl;
    return 0;
}
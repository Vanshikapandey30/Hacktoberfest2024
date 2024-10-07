/*
Hi, this is a simple program to convert a normal expression to an prefix or a postfix expression.
I have used to seperate functions for that
Created a class called stack to house the stack.
*/

#include <bits/stdc++.h>
using namespace std;

# define n 100

string symbol1 = "%/+";
string symbol2 = " *-";
int i, j;

class Stack{
    char op[n];
    int topn;
    public:
    Stack(){
        topn = -1;
    }
    char top(){
        if (topn == n)
            return '\0';
        return op[topn];
    }
    void push(char c){
        if(topn == n)
            return;
        topn++;
        op[topn] = c;
        return;
    }
    void pop(){
        if(topn == -1)
            return;
        topn--;
    }
    bool empty(){
        return topn==-1;
    }
    void display(){
        cout << "display stack\n";
        for(int i = topn; i >= 0; i--){
            cout << op[topn] << endl;
        }
    }
};

int prec(char c){
    switch(c){
        case '^': return 5;
        case '%': return 4;
        case '/': return 3;
        case '*': return 2;
        case '+': return 1;
        case '-': return 1;
        default: return 0;
    }
}

string postfix(string s){
    string postfix;
    Stack st;
    string res;
    char c;
    s = '('+ s +')';
    for (int i = 0; i < s.length(); i++) {
        c = s[i];
        if(isspace(c) || c == ',')
            continue;
        else if (isalpha(c)) {
            res += c;
            continue;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop(); // pop the '('
            }
        }
        else {
            if(c == '^'){
                while ((prec(st.top()) >= prec(c))) {
                    res += st.top();
                    st.pop();
                }
            }
            else{
                while ((prec(st.top()) > prec(c))) {
                    res += st.top();
                    st.pop();
                }
            }
            st.push(c);   
            }
        }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}
string prefix(string s){
    reverse(s.begin(), s.end());
    cout << s << endl;
    Stack st;
    string res;
    char c;

    s = ')'+ s +'(';
    for (int i = 0; i < s.length(); i++) {
        c = s[i];
        if(isspace(c) || c == ',')
            continue;
        else if (isalpha(c)) {
            res += c;
            continue;
        }
        else if (c == ')') {
            st.push(c);
        }
        else if (c == '(') {
            while (!st.empty() && st.top() != ')') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop(); // pop the '('
            }
        }
        else {
            if(c == '^'){
                while ((prec(st.top()) >= prec(c))) {
                    res += st.top();
                    st.pop();
                }
            }
            else{
                while ((prec(st.top()) > prec(c))) {
                    res += st.top();
                    st.pop();
                }
            }
            st.push(c);   
            }
        }
        while(! st.empty()){
            res += st.top();
            st.pop();
        }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cout << "WELCOME TO INFIX CONVERSION!" << endl;
    cout << "Infix expression: The expression of the form \"a operator b\" (a + b) i.e., when an operator is in-between every pair of operands.\n";
    cout << "1. Postfix expression: The expression of the form \"a b operator\" (ab+) i.e., When every pair of operands is followed by an operator.\n2. Prefix Expression: The expression of type \'operator\' a b (+ab where + is an operator) i.e., when the operator is placed before the operands.\n\n";
    cout << "ENTER YOUR CHOICE 1 or 2: ";
    int choice;
    cin >> choice;
    string exp;
    cout << "ENTER YOUR EXPRESSION: ";
    cin >> exp;
    switch(choice){
        case 1:
        cout << "\n----POSTFIX EXPRESSION----\n";
        cout << "Infix: " << exp << "\nPostfix: " << postfix(exp) << endl << endl;
        break;

        case 2:
        cout << "\n----PREFIX EXPRESSION----\n";
        cout << "Infix: " << exp << "\nPrefix: " << prefix(exp) << endl;
        break;

        default:
        cout << "Invalid choice" << endl;
        break;
    }
    
    return 0;
}
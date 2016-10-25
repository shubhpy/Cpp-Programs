#include <iostream>
#include <stack>
#include <string>

using namespace std;

int Parenthesis(stack<char>& mystack,stack<int>& intstack,string text){
    int position;
    for (position = 0; position < text.length(); position++) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            mystack.push(next);
            intstack.push(position);
        }
        else if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (not mystack.empty()){
                char top = mystack.top();
                if (top=='(' && next != ')'){
                    return position;
                    }
                if (top=='{' && next != '}'){
                    return position;
                    }
                if (top=='[' && next != ']'){
                    return position;
                    }
                mystack.pop();
                intstack.pop();
            }
            else{
                return position;
                }
        }
    }

    if(mystack.empty()){
       return -1;
        }
    else{
        return intstack.top();
        }
    }

int main() {
    string text;
    getline(cin, text);

    //stack <Bracket> opening_brackets_stack;
    stack<char> mystack;
    stack<int> intstack;

    int ans = Parenthesis(mystack,intstack,text);
    if (ans!=-1){
        cout << ans+1;
        }
    else{
        cout << "Success";
        }

    return 0;
}

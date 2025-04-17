#include <string>
#include <stack>
#include <cstdio>

using namespace std;

bool solution(string s)
{   
    stack<char> stk;
    for(char c : s) {
        if(c == '(') {
            stk.push('(');
        }
        else if(stk.empty()) {
            return false;
        }
        else {
            stk.pop();
        }
    }
    if(stk.empty()) {
        return true;
    }
    else {
        return false;
    }
}
// no.1918: 후위 표기식 (G2)

#include <cstdio>
#include <stack>
using namespace std;

bool isOp(char c);
int compare(char op1, char op2);

int main() {
    char exp[101];
    scanf("%s", exp);
    stack<char> op;
    for(int i=0; exp[i]!=0; i++) {
        if(isOp(exp[i])) {
            if(op.empty() || op.top() == '(' || compare(exp[i], op.top()) > 0) {
                op.push(exp[i]);
                continue;
            }
            while(!op.empty() && op.top() != '(' && compare(exp[i], op.top()) <= 0) {
                printf("%c", op.top());
                op.pop();
            }
            op.push(exp[i]);
        }
        else if(exp[i] == '(') {
            op.push(exp[i]);
        }
        else if(exp[i] == ')') {
            while(op.top() != '(') {
                printf("%c", op.top());
                op.pop();
            }
            op.pop();
        }
        else {
            printf("%c", exp[i]);
        }
    }
    while(!op.empty()) {
        printf("%c", op.top());
        op.pop();
    }
    printf("\n");
    return 0;
}

int compare(char op1, char op2) {
    if(op1 == '+' || op1 == '-') {
        if(op2 == '+' || op2 == '-') {
            return 0;
        }
        else {
            return -1;
        }
    }
    else {
        if(op2 == '+' || op2 == '-') {
            return 1;
        }
        else {
            return 0;
        }
    }
}

bool isOp(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }
    return false;
}

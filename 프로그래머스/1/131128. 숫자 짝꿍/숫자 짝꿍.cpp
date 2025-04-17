#include <string>
#include <vector>

using namespace std;

bool isEmpty();
bool isZero();

vector<int> count(10, 0);
vector<int> ret(10, 0);

string solution(string X, string Y) {
    for(char x : X) {
        count[x-'0']++;
    }
    for(char y : Y) {
        if(ret[y-'0'] < count[y-'0']) {
            ret[y-'0']++;
        }
    }
    
    if(isEmpty()) {
        return "-1";
    }
    if(isZero()) {
        return "0";
    }
    string answer = "";
    for(int i=9; i>=0; i--) {
        if(ret[i] > 0) {
            for(int j=0; j<ret[i]; j++) {
                answer = answer.append(to_string(i));
            }
        }
    }
    return answer;
}

bool isEmpty() {
    for(int i=0; i<10; i++) {
        if(ret[i] != 0) {
            return false;
        }
    }
    return true;
}

bool isZero() {
    for(int i=0; i<10; i++) {
        if(ret[i] != 0 && i != 0) {
            return false;
        }
    }
    return true;
}
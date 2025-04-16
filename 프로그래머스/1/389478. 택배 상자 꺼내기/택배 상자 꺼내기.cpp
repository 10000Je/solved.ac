#include <string>
#include <vector>

using namespace std;

int get_x(int n, int w);
int get_y(int n, int w);

int solution(int n, int w, int num) {
    int answer = get_y(n, w) - get_y(num, w);
    int y = get_y(n, w);
    if(y%2 == 0 && get_x(num, w) >= get_x(n, w)) {
        answer++;
    }
    if(y%2 != 0 && get_x(num, w) <= get_x(n, w)) {
        answer++;
    }
    return answer;
}

int get_x(int n, int w) {
    int y = get_y(n, w);
    int x = n%w;
    if(y%2 == 0) {
        if(x != 0) {
            x = w-x;
        }
    }
    else {
        if(x == 0) {
            x = w-1;
        }
        else {
            x--;
        }
    }
    return x;
}

int get_y(int n, int w) {
    return (n%w==0) ? n/w : n/w+1;
}
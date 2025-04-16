#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    while(num <= n) {
        answer++;
        num = num + 2*((w - (num%w))%w)+1;
    }
    return answer;
}
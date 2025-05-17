// no.1920: 수 찾기 (S4)

#include <cstdio>
#include <unordered_set>
#include <cstring>
#include <cstdlib>
using namespace std;

char a[1'200'000];
char b[1'200'000];

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    fgets(a, 1'200'000, stdin);

    unordered_set<int> arr;
    char* temp = strtok(a, " ");
    while(temp != NULL) {
        arr.insert(atoi(temp));
        temp = strtok(NULL, " ");
    }

    int m;
    scanf("%d", &m);
    getchar();
    fgets(b, 1'200'000, stdin);

    temp = strtok(b, " ");
    while(temp != NULL) {
        if(arr.find(atoi(temp)) != arr.end()) {
            printf("1\n");
        } else {
            printf("0\n");
        }
        temp = strtok(NULL, " ");
    }
    return 0;
}
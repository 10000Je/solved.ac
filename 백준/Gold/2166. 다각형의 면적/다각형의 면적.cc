// no.2166: 다각형의 면적

#include <cstdio>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

typedef long long int64;

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> dots;
    for(int i=0; i<n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        dots.push_back(make_pair(x, y));
    }
    int64 area = 0;
    for(int i=0; i<n; i++) {
        int a = dots[i-1].first - dots[0].first;
        int b = dots[i-1].second - dots[0].second;
        int c = dots[i].first - dots[0].first;
        int d = dots[i].second - dots[0].second;
        area += ((int64)a*d-(int64)b*c);
    }
    printf("%.1f\n", abs(area/2.0));
    return 0;
}
// no.1202: 보석 도둑 (G2)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int64;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> items(n);
    for(int i=0; i<n; i++) {
        int m, v;
        cin >> m >> v;
        items[i] = make_pair(m, v);
    }
    sort(items.begin(), items.end());
    vector<int> bag(k);
    for(int i=0; i<k; i++) {
        int c;
        cin >> c;
        bag[i] = c;
    }
    sort(bag.begin(), bag.end());
    priority_queue<int> heap;
    int idx = 0;
    int64 total = 0;
    for(int c : bag) {
        while(idx < n && items[idx].first <= c) {
            heap.push(items[idx].second);
            idx++;
        }
        if(!heap.empty()) {
            total += heap.top();
            heap.pop();
        }
    }
    cout << total << '\n';
    return 0;
}
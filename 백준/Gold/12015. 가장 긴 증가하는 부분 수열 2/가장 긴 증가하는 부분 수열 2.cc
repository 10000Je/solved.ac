// no.12015: 가장 긴 증가하는 부분 수열 2 (G2)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insert(int val, vector<int>& lis);

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> lis;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        insert(a, lis);
    }
    cout << lis.size() << '\n';
    return 0;
}

void insert(int val, vector<int>& lis)
{
    if(lis.empty())
    {
        lis.push_back(val);
        return;
    }
    int idx = distance(lis.begin(), lower_bound(lis.begin(), lis.end(), val));
    if(idx >= lis.size())
        lis.push_back(val);
    else
        lis[idx] = val;
}
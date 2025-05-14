// no.12015: 가장 긴 증가하는 부분 수열 2 (G2)

#include <iostream>
#include <vector>
using namespace std;

void insert(int val, vector<int>& lis);
int binary_search(int val, int left, int right, const vector<int>& lis);

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
    int idx = binary_search(val, 0, lis.size()-1, lis);
    if(idx >= lis.size())
        lis.push_back(val);
    else
        lis[idx] = val;
}

int binary_search(int val, int left, int right, const vector<int>& lis)
{
    if(left > right)
        return left;
    int mid = (left + right) / 2;
    if(val <= lis[mid])
        return binary_search(val, left, mid-1, lis);
    else
        return binary_search(val, mid+1, right, lis);
}


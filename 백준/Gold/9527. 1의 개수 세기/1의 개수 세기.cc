// no.9527: 1의 개수 세기 (G2)

#include <iostream>
#include <vector>
#define MAX 60
using namespace std;

typedef long long int64;

int64 count(int64 n, vector<int64>& dp);

int main()
{
    int64 a, b;
    cin >> a >> b;
    vector<int64> dp(MAX, 0);
    dp[0]= 1;
    for(int i=1; i<MAX; i++)
        dp[i] = (1LL<<i) + dp[i-1]*2;
    cout << count(b, dp) - count(a-1, dp) << '\n';
    return 0;
}

int64 count(int64 n, vector<int64>& dp) 
{
    int64 result = 0;
    for(int i=MAX; i>0; i--)
    {   
        if((n&(1LL<<i)) == 0)
            continue;
        result += dp[i-1] + (n-((1LL<<i)-1));
        n = n&(~(1LL<<i));
    }
    result += n;
    return result;
}
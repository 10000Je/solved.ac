// no.11444: 피보나치 수 6 (G2)

#include <cstdio>
#include <vector>
#define R 1'000'000'007
using namespace std;

typedef long long int64;

vector<vector<int>> power(const vector<vector<int>>& matrix, int64 n);
vector<vector<int>> multiply(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2);

int main() {
    int64 n;
    scanf("%lld", &n);
    vector<vector<int>> basic = {
        {0, 1},
        {1, 1}
    };
    vector<vector<int>> ret = power(basic, n);
    printf("%d\n", ret[0][1]);
    return 0;
}

vector<vector<int>> power(const vector<vector<int>>& matrix, int64 n) {
    if(n == 1) {
        return matrix;
    }
    vector<vector<int>> tmp = power(matrix, n/2);
    if(n%2 == 0) {
        return multiply(tmp, tmp); 
    }
    else {
        return multiply(multiply(tmp, tmp), matrix);
    }
}

vector<vector<int>> multiply(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    vector<vector<int>> ret = {
        {0, 0},
        {0, 0}
    };
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<2; k++) {
                ret[i][j] += ((int64)matrix1[i][k]*matrix2[k][j])%R;
                ret[i][j] %= R;
            }
        }
    }
    return ret;
}

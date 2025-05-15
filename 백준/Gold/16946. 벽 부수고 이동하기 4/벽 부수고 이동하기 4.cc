// no.16946: 벽 부수고 이동하기 4 (G2)

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <functional>
using namespace std;

pair<int, int> parent[1000][1000];

pair<int, int> find(const pair<int, int>& x);
void _union(const pair<int, int>& a, const pair<int, int>& b);

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    // init
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            parent[i][j] = make_pair(i, j);

    vector<vector<int>> map(n, vector<int>(m, 0));
    for(int i=0; i<n; i++)
    {
        string str;
        cin >> str;
        for(int j=0; j<m; j++)
            map[i][j] = str[j] - '0';
    }

    // get disjoint set
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(map[i][j] == 1)
                continue;
            vector<pair<int, int>> nodes =
            {
                make_pair(i-1, j), make_pair(i+1, j),
                make_pair(i, j-1), make_pair(i, j+1)
            };
            for(pair<int, int> node : nodes)
            {
                int r = node.first, c = node.second;
                if(r < 0 || r >= n || c < 0 || c >= m)
                    continue;
                if(map[r][c] == 0)
                    _union(make_pair(i, j), node);
            }
        }
    }

    // count
    vector<vector<int>> count_arr(n, vector<int>(m, 0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            pair<int, int> root = find(make_pair(i, j));
            count_arr[root.first][root.second]++;
        }
    }

    // calculate
    vector<string> results;
    for(int i=0; i<n; i++)
    {
        string result;
        for(int j=0; j<m; j++)
        {
            if(map[i][j] == 0)
            {
                result.push_back('0');
                continue;
            }
            set<pair<int, int>> roots;
            vector<pair<int, int>> nodes =
            {
                make_pair(i-1, j), make_pair(i+1, j),
                make_pair(i, j-1), make_pair(i, j+1)
            };
            for(pair<int, int> node : nodes)
            {
                int r = node.first, c = node.second;
                if(r < 0 || r >= n || c < 0 || c >= m)
                    continue;
                if(map[r][c] == 1)
                    continue;
                roots.insert(find(node));
            }
            int cnt = 1;
            for(pair<int, int> root : roots)
            {
                cnt += count_arr[root.first][root.second];
            }
            cnt %= 10;
            result.push_back((char)(cnt+'0'));
        }
        results.push_back(result);
    }
    for(string result : results)
        cout << result << '\n';
    return 0;
}

pair<int, int> find(const pair<int, int>& x)
{
    int i = x.first, j = x.second;
    if(parent[i][j] != x)
        parent[i][j] = find(parent[i][j]);
    return parent[i][j];
}

void _union(const pair<int, int>& a, const pair<int, int>& b)
{
    pair<int, int> root_a = find(a);
    pair<int, int> root_b = find(b);
    int i = root_b.first, j = root_b.second;
    parent[i][j] = root_a;
}
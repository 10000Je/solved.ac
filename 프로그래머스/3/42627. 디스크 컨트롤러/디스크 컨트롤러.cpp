#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int t = 0;
int sum = 0;
priority_queue<pair<int, int>> wait;

void push(vector<vector<int>>& jobs);

int solution(vector<vector<int>> jobs) {
    size_t count = jobs.size();
    sort(jobs.begin(), jobs.end(), greater<vector<int>>());
    push(jobs);
    while(!wait.empty()) {
        int burst = -wait.top().first;
        int start = -wait.top().second;
        wait.pop();
        sum += (burst + t-start);
        t += burst;
        push(jobs);
    }
    return sum / count;
}

void push(vector<vector<int>>& jobs) {
    if(jobs.empty()) {
        return;
    }
    int start = jobs.back()[0];
    int burst = jobs.back()[1];
    if(start > t && wait.empty()) {
        t = start;
    }
    while(start <= t) {
        wait.push(make_pair(-burst, -start));
        jobs.pop_back();
        if(jobs.empty()) {
            return;
        }
        start = jobs.back()[0];
        burst = jobs.back()[1];
    }
}
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isFinished(vector<bool>& visit);
int getCard(vector<bool>& visit);

int solution(vector<int> cards) {
    int n = cards.size();
    vector<bool> visit(n+1, false);
    vector<int> group;
    int n1 = 0, n2 = 0;
    
    int card = 1;
    while(!isFinished(visit)) {
        int count = 0;
        while(!visit[card]) {
            visit[card] = true;
            card = cards[card-1];
            count++;
        }
        card = getCard(visit);
        group.push_back(count);
    }
    
    if(group.size() == 1) {
        return 0;
    }
    else {
        sort(group.begin(), group.end(), greater<int>());
        return group[0]*group[1];
    }
}

bool isFinished(vector<bool>& visit) {
    int n = visit.size()-1;
    for(int i=1; i<=n; i++) {
        if(!visit[i]) {
            return false;
        }
    }
    return true;
}

int getCard(vector<bool>& visit) {
    int n = visit.size()-1;
    for(int i=1; i<=n; i++) {
        if(!visit[i]) {
            return i;
        }
    }
    return -1;
}
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/3/ALDS1_3_B

#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;

typedef long long ll;

typedef pair<string, int> proc;
queue<proc> q;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, max, et;
    cin >> n;
    cin >> max;
    et = 0;

    REP(i, n) {
        string name;
        int time;
        cin >> name;
        cin >> time;
        proc p = proc(name, time);
        q.push(p);
    }

    while(!q.empty()) {
        proc p;
        p = q.front();
        q.pop();
        int t = p.second;

        if (t > max) {
            p.second = t - max;
            q.push(p);
            et += max;
        } else {
            et += t;
            cout << p.first << ' ' << et << "\n";
        }
    }
}
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/3/ALDS1_3_C

#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;

typedef long long ll;

list<int> L;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    REP(i, n) {
        string com;
        int key;
        cin >> com;

        if (com == "insert") {
            cin >> key;
            L.push_front(key);
        } else if (com == "delete") {
            cin >> key;
            for (auto it = L.begin(); it != L.end(); ++it) {
                if (*it == key) {
                    L.erase(it);
                    break;
                }
            }
        } else if (com == "deleteFirst") {
            L.pop_front();
        } else if (com == "deleteLast") {
            L.pop_back();
        }
    }

    int i = 0;
    for (int k : L) {
        if (i++) cout << ' ';
        cout << k;
    }
    cout << "\n";
}

// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_A

#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;

typedef long long ll;

bool linearSearch(int A[], int n, int key) {
    A[n] = key;
    int i = 0;
    while (A[i] != key) ++i;
    return i != n;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    
    int A[n];
    REP(i, n) cin >> A[i];

    int q; cin >> q;
    int ans = 0;
    REP(i, q) {
        int key;
        cin >> key;
        if (linearSearch(A, n, key)) ++ans;
    }

    cout << ans << "\n";
} 
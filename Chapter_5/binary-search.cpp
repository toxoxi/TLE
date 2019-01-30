// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B

#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;

typedef long long ll;

bool binarySearch(int A[], int n, int key) {
    int left = 0;
    int right = n;
    int mid = -1;

    while (left < right) {
        mid = (left+right) / 2;
        if (A[mid] == key) return true;
        else if (A[mid] > key) right = mid;
        else left = mid+1;
    }
    return false;
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
        if (binarySearch(A, n, key)) ++ans;
    }

    cout << ans << "\n";
} 
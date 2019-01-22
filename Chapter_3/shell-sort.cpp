// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/2/ALDS1_2_D

#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;

typedef long long ll;

int cnt;
int l;
int arr[10000000];
int n;
vector<int> G;

void insertionSort(int arr[], int g) {
    FOR(i, g, n) {
        int v = arr[i];
        int j = i - g;
        while (j >= 0 && arr[j] > v) {
            arr[j+g] = arr[j];
            j -= g;
            ++cnt;
        }
        arr[j+g] = v;
    }
}

void shellSort(int arr[]) {
    // 数列生成
    int h = 1;
    while(h <= n) {
        G.push_back(h);
        h = 3*h + 1;
    }

    // 逆順にG[i] = gを指定
    REPR(i, G.size() - 1) {
        insertionSort(arr, G[i]);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;

    REP(i, n) cin >> arr[i];
    cnt = 0;

    shellSort(arr);

    int size = G.size();
    cout << size << endl;
    REPR(i, size - 1) {
        cout << G[i];
        if (i) cout << " ";
    }
    cout << "\n";
    cout << cnt << "\n";
    REP(i, n) cout << arr[i] << "\n";
}
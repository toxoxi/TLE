// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/3/ALDS1_3_A

#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;

typedef long long ll;

stack<int> s;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string str;   
    while (cin >> str) {
        if (str == "+" || str == "-" || str == "*") {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if (str == "+") {
                s.push(b + a);
            } else if (str == "-") {
                s.push(b - a);
            } else if (str == "*") {
                s.push(b * a);
            }
        } else {
            s.push(atoi(str.c_str()));
        }
    }

    cout << s.top() << "\n";
}

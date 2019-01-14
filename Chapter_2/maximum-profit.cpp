#include <iostream>
#include <fstream>
using namespace std;

static const int MAX = 200000;

int main() {
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
   	ios::sync_with_stdio(false);

    int R[MAX], n;

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> R[i];

    int maxv = -200000000; // 十分小さい値
    int minv = R[0];

    for (int i = 1; i < n; ++i) {
        maxv = max(maxv, R[i] - minv); // 最大値を更新
        minv = min(minv, R[i]); // 最小値を保存しておく
        cout << i << "回目のループ: " << maxv << " " << minv << endl;
    }

    cout << maxv << endl;
}
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_2_C

#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;

typedef long long ll;

struct Card { char suit, value; };

// 左のカードと比較し続ける
void bubbleSort(Card cards[], int n) {
    // 5枚のカードを1枚ずつループ
    REP(i, n) {
        // 5枚目のカードからi枚目まで一枚ずつ比較して入れ替える
        for (int j = n-1; j >= i; --j) {
            // もしj枚目のカードよりj-1枚目のカードの方が大きい場合swap
            if (cards[j].value < cards[j-1].value) {
                swap(cards[j], cards[j-1]);
            }
            // 左のカードとの比較を繰り替えす
        }
    }
}

// 最小値を取り続ける
void selectionSort(Card cards[], int n) {
    int minj;
    // 5枚のカードを1枚ずつループ
    REP(i, n) {
        minj = i;
        // i枚目のカードから5枚目までループ
        FOR(j, i, n) {
            if (cards[j].value < cards[minj].value) {
                minj = j;
            }
        }
        swap(cards[i], cards[minj]);
    }
}

void printCards(Card cards[], int n) {
    REP(i, n) {
        cout << cards[i].suit << cards[i].value;
        if (i < n-1) {
            cout << ' ';
        } else {
            cout << "\n";
        };
    };
}

bool isSame(Card a[], Card b[], int n) {
    REP(i, n) if (a[i].suit != b[i].suit) return false;
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    Card cards1[n];
    Card cards2[n];

    // 入力の読み込み
    REP(i, n) cin >> cards1[i].suit >> cards1[i].value;
    // 配列をコピー
    REP(i, n) cards2[i] = cards1[i];

    bubbleSort(cards1, n);
    printCards(cards1, n);

    // バブルソートは安定ソート
    cout << "Stable" << "\n";

    selectionSort(cards2, n);
    printCards(cards2, n);

    bool isStable = isSame(cards1, cards2, n);
    if (isStable){
        cout << "Stable" << "\n";
    } else {
        cout << "Not stable" << "\n";
    }
}

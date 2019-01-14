#include <iostream>
#include <string>
using namespace std;

int v, j;

void printArr(int A[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << A[i];
        if (i < n-1)
            cout << ' ';
    }
    cout << endl;
}

void insertionSort(int A[], int N) {
    printArr(A, N);

    for (int i = 1; i <= N-1; ++i) {
        v = A[i]; // i個目の値
        j = i-1; // 0 ~ N
        while (j >= 0 && A[j] > v) { // 0~N が 0以上 && vの1個前の値が v以上
            A[j+1] = A[j]; // A[j]を一つ後ろへ
            j--; // vとの比較対象を一つ小さな値へ
        }
        A[j+1] = v;
        printArr(A, N);
    }
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    insertionSort(arr, n);
}
#include<iostream>
#include<algorithm>

using namespace std;
int n, m, a, b, c;
int use[10];
int isu[10];
int arr[10];
void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!isu[use[i]]) {
            arr[k] = use[i];
            isu[use[i]] = 1;
            func(k + 1);
            isu[use[i]] = 0;
        }
    }
 }
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> use[i];
    }
    sort(use, use + n);
    func(0);
}
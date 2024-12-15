#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n), cnt(23);
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (i >= 6) {
            ++cnt[arr[i - 6] % 23];
            res += cnt[arr[i] % 23];
        }
    }
    cout << res;
    return 0;
}

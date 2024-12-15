#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

vector<int> BIT(MAXN, 0);

struct Dev {
    int a, h, id;

    bool operator<(const Dev &other) const {
        return a == other.a ? h < other.h : a < other.a;
    }
};

void update(int id, int val = 1) {
    if (id <= MAXN) BIT[id] += val, update(id + (id & -id), val);
}

int get(int id) {
    return !id ? 0 : BIT[id] + get(id - (id & -id));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<Dev> arr(n);
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].a >> arr[i].h;
        arr[i].id = i;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n && arr[j].a == arr[i].a) ++j;
        --j;
        for (int k = i; k <= j; ++k) {
            res[arr[k].id] += get(arr[k].h + 1);
        }
        for (int k = i; k <= j; ++k) {
            update(arr[k].h + 1);
        }
        int l = i;
        for (int k = i; k <= j; ++k) {
            while (l <= j && arr[l].h < arr[k].h) ++l;
            res[arr[k].id] += l - i;
        }
        i = j;
    }
    for (int num: res) cout << num << '\n';
    return 0;
}

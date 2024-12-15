#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MAXN = 100005;

vector<int> tree[MAXN];
int color[MAXN];
unordered_map<int, int> color_count[MAXN];
int distinct_colors[MAXN];

void dfs(int node, int parent) {
    color_count[node][color[node]]++;
    distinct_colors[node] = 1;
    for (int child : tree[node]) {
        if (child == parent) continue;
        dfs(child, node);
        if (color_count[node].size() < color_count[child].size()) {
            swap(color_count[node], color_count[child]);
            distinct_colors[node] = distinct_colors[child];
        }
        for (auto& entry : color_count[child]) {
            int col = entry.first;
            int cnt = entry.second;
            if (color_count[node][col] == 0) {
                distinct_colors[node]++;
            }
            color_count[node][col] += cnt;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> color[i];
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        cout << distinct_colors[i] << '\n';
    }
    return 0;
}

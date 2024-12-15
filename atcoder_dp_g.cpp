#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
vector<vector<int>> adj;

int dfs(int u) {
    if (dp[u]) return dp[u];
    for (int v: adj[u]) {
        if (!dp[v]) dp[v] = dfs(v);
        dp[u] = max(dp[u], dp[v] + 1);
    }
    return dp[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    adj.assign(n + 5, vector<int>());
    dp.assign(n + 5, 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) dfs(i);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}

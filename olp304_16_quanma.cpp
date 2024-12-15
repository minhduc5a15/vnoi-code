#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct Knight {
    int x, y, steps;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifstream inp("QUANMA.INP");
    ofstream out("QUANMA.OUT");
    int n, m;
    inp >> n >> m;
    vector<vector<bool>> visited(n + 1, vector(m + 1, false));
    vector<int> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
    queue<Knight> q;
    int x1, y1;
    inp >> x1 >> y1;
    q.push({x1, y1, 0});
    visited[x1][y1] = true;
    int x2, y2;
    inp >> x2 >> y2;
    while (!q.empty()) {
        Knight top = q.front();
        q.pop();
        if (top.x == x2  && top.y == y2) {
            out << top.steps;
            return 0;
        }
        for (int i = 0; i < 8; ++i) {
            int nx = top.x + dx[i];
            int ny = top.y + dy[i];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && !visited[nx][ny]) {
                q.push({nx, ny, top.steps + 1});
                visited[nx][ny] = true;
            }
        }
    }
    out << -1;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, m, q;
bool used[MAXN][MAXN], visited[MAXN * MAXN];
vector<int> g[MAXN*MAXN];
int matching[MAXN * MAXN];

bool dfs(int v) {
    if (visited[v]) return false;
    visited[v] = true;
    for (int to : g[v]) {
        if (matching[to] == -1 || dfs(matching[to])) {
            matching[to] = v;
            return true;
        }
    }
    return false;
}

int kuhn() {
    memset(matching, -1, sizeof(matching));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!used[i][j]) {
                memset(visited, false, sizeof(visited));
                if (dfs((i - 1) * m + j)) {
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main() {
    cin >> n >> m >> q;
    int x, y;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        used[x][y] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!used[i][j]) {
                if (i > 1 && !used[i-1][j]) {
                    g[(i-1)*m+j].push_back((i-2)*m+j);
                }
                if (j > 1 && !used[i][j-1]) {
                    g[(i-1)*m+j].push_back((i-1)*m+j-1);
                }
                if (i < n && !used[i+1][j]) {
                    g[(i-1)*m+j].push_back(i*m+j);
                }
                if (j < m && !used[i][j+1]) {
                    g[(i-1)*m+j].push_back((i-1)*m+j+1);
                }
            }
        }
    }
    cout << kuhn() << endl;
    return 0;
}
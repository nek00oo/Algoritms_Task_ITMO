#include <iostream>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

struct Edge {
    int u, v, w;
};

struct CompareEdgesByWeight {
    bool operator()(const Edge &e1, const Edge &e2) const {
        return e1.w > e2.w;
    }
};

struct Dsu {
    vector<long int> color;
    int n;

    Dsu (long int n) {
        this->n = n;
        color = vector<long int>(n);
        iota(color.begin(), color.end(), 0);
    }

    int root(long int x) {
        if (color[x] == x) {
            return x;
        }
        return color[x] = root(color[x]);
    }

    void Union(long int x, long int y) {
        x = root(x);
        y = root(y);
        if (x == y) {
            return;
        }
        color[x] = color[y];
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long int n, m;
    cin >> n >> m;
    Dsu dsu(n+1);
    long int a,b,c;
    priority_queue<Edge, vector<Edge>, CompareEdgesByWeight> edges;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        edges.push( {a,b,c});
    }
    long int answer = 0;
    while(!edges.empty()){
        long int rib_weight = edges.top().w;
        long int a1 = edges.top().u;
        long int b1 = edges.top().v;
        edges.pop();
        if (dsu.root(a1) != dsu.root(b1)){
            dsu.Union(a1,b1);
            answer+=rib_weight;
        }
    }

    cout << answer;

    return 0;
}
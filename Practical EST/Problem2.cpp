#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rankArr;

public:
    DSU(int n) {
        parent.resize(n);
        rankArr.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rankArr[a] < rankArr[b]) swap(a, b);
            parent[b] = a;
            if (rankArr[a] == rankArr[b]) rankArr[a]++;
        }
    }
};

int manhattan(pair<int,int> a, pair<int,int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int kruskalMST(vector<pair<int,int>> &points) {
    int n = points.size();

    vector<tuple<int,int,int>> edges;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = manhattan(points[i], points[j]);
            edges.push_back({dist, i, j});
        }
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int mstCost = 0;

    for (auto &e : edges) {
        int w, u, v;
        tie(w, u, v) = e;

        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            mstCost += w;
        }
    }

    return mstCost;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    cout << kruskalMST(points) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<long long> bit;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void build(vector<long long> &arr) {
        for (int i = 0; i < n; i++) {
            update(i + 1, arr[i]);
        }
    }

    void update(int index, long long value) {
        while (index <= n) {
            bit[index] += value;
            index += index & -index;
        }
    }

    long long prefixSum(int index) {
        long long sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & -index;
        }
        return sum;
    }

    long long rangeSum(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> arr(n, 0);

    FenwickTree ft(n);
    ft.build(arr);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int i;
            long long v;
            cin >> i >> v;
            ft.update(i, v);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << ft.rangeSum(l, r) << endl;
        }
    }

    return 0;
}

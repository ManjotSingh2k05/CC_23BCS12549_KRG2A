#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> seg;
vector<int> lazy;

void build(int ind, int low, int high) {
    if (low == high) {
        seg[ind] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

void push(int ind, int low, int high) {
    if (lazy[ind] != 0) {
        seg[ind] += lazy[ind];

        if (low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }

        lazy[ind]=0;
    }
}

void update(int ind, int low, int high, int l, int r, int val) {
    push(ind, low, high);

    // No overlap
    if (r < low || high < l) return;

    // Complete overlap
    if (l <= low && high <= r) {
        lazy[ind] += val;
        push(ind,low,high);
        return;
    }

    // Partial overlap
    int mid = (low + high) / 2;
    update(2 * ind + 1, low, mid, l, r, val);
    update(2 * ind + 2, mid + 1, high, l, r, val);

    seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
}

int query(int ind, int low, int high, int l, int r) {
    push(ind, low, high);

    // No overlap
    if (r < low || high < l) return INT_MIN;

    // Complete overlap
    if (l <= low && high <= r) return seg[ind];

    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);

    return max(left, right);
}

int main() {
    int n;
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    seg.resize(4 * n);
    lazy.resize(4 * n, 0);

    build(0, 0, n - 1);

    cout << "Max in range (1,3): " << query(0, 0, n - 1, 1, 3) << endl;

    // add +10 from index 1 to 3
    update(0, 0, n - 1, 1, 3,10);

    cout << "After update, Max in range (1,3): "
         << query(0, 0, n - 1, 1, 3) << endl;

    return 0;
}
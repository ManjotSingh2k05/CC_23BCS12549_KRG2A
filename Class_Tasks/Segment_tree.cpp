#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void build(int index, int low, int high, vector<int> &arr, vector<int> &seg) {
    if (low == high) {
        seg[index] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * index + 1, low, mid, arr, seg);
    build(2 * index + 2, mid + 1, high, arr, seg);

    seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
}

int query(int index, int low, int high, int l, int r, vector<int> &seg) {
    if (low > r || high < l) {
        return INT_MIN;
    }

    if (low >= l && high <= r) {
        return seg[index];
    }

    int mid = (low + high) / 2;
    int left = query(2 * index + 1, low, mid, l, r, seg);
    int right = query(2 * index + 2, mid + 1, high, l, r, seg);

    return max(left, right);
}

int main() {
    vector<int> arr = {1, 3, 2, 7, 9, 11, 12, 2};
    int n = arr.size();
    vector<int> seg(4 * n);
    build(0, 0, n - 1, arr, seg);

    int l = 1, r = 6;
    cout << "Maximum in range [" << l << ", " << r << "] is: "
         << query(0, 0, n - 1, l, r, seg);

    return 0;
}

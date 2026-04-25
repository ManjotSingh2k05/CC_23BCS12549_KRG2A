class SegmentTree {
public:
    vector<int> tree;
    int size;

    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n, 0);
    }

    void update(int index, int value, int node, int start, int end) {
        if (start == end) {
            tree[node] += value;
            return;
        }

        int mid = (start + end) / 2;
        if (index <= mid)
            update(index, value, 2 * node, start, mid);
        else
            update(index, value, 2 * node + 1, mid + 1, end);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int left, int right, int node, int start, int end) {
        if (right < start || end < left)
            return 0;

        if (left <= start && end <= right)
            return tree[node];

        int mid = (start + end) / 2;
        return query(left, right, 2 * node, start, mid) +
               query(left, right, 2 * node + 1, mid + 1, end);
    }
};
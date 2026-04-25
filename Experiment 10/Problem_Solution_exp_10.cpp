class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        // Coordinate Compression
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        unordered_map<int, int> rank;
        for (int i = 0; i < sorted.size(); i++) {
            rank[sorted[i]] = i;
        }

        SegmentTree tree(sorted.size());

        // Traverse from right
        for (int i = n - 1; i >= 0; i--) {
            int r = rank[nums[i]];

            if (r > 0)
                result[i] = tree.query(0, r - 1, 1, 0, tree.size - 1);
            else
                result[i] = 0;

            tree.update(r, 1, 1, 0, tree.size - 1);
        }

        return result;
    }
};
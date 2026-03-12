#include <bits/stdc++.h>
using namespace std;

long long maxSquareSum(vector<int>& nums) {
    vector<int> bitCount(32, 0);

    for (int x : nums)
        for (int b = 0; b < 32; b++)
            if (x & (1 << b))
                bitCount[b]++;

    long long ans = 0;

    while (true) {
        int cur = 0;
        bool found = false;

        for (int b = 0; b < 32; b++) {
            if (bitCount[b] > 0) {
                cur |= (1 << b);
                bitCount[b]--;
                found = true;
            }
        }

        if (!found) break;

        ans += 1LL * cur * cur;
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    cout << maxSquareSum(nums);
}

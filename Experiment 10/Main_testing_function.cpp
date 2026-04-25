#include <bits/stdc++.h>
using namespace std;

int main() {
    Solution obj;

    vector<int> nums = {5, 2, 6, 1};
    vector<int> ans = obj.countSmaller(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
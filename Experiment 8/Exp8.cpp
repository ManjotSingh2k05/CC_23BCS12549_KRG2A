#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> k;

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 1; j <= k && i - j >= 0; j++) {
            mx = max(mx, arr[i - j]);
            dp[i] = max(dp[i], dp[i - j] + mx * j);
        }
    }

    cout << dp[n];
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; long long S;
    if(cin >> n >> S) {
        vector<long long> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        int l = 0, r = n, ans_k = 0;
        long long ans_T = 0;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            vector<long long> b(n);
            for(int i=0; i<n; i++) b[i] = a[i] + (long long)(i + 1) * mid;
            sort(b.begin(), b.end());
            long long cost = 0;
            for(int i=0; i<mid; i++) cost += b[i];
            if(cost <= S) {
                ans_k = mid;
                ans_T = cost;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans_k << " " << ans_T << "\n";
    }
    return 0;
}

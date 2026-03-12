#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; 
    if(cin >> n) {
        map<string, int> m;
        string s, ans;
        int mx = 0;
        for(int i=0; i<n; i++) {
            cin >> s;
            m[s]++;
            if(m[s] > mx) {
                mx = m[s];
                ans = s;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

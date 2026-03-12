#include <bits/stdc++.h>
using namespace std;
const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const long long P1 = 31;
const long long P2 = 37;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    if(cin >> n >> m) {
        set<pair<long long, long long>> hashes;
        for(int i=0; i<n; i++) {
            string s; cin >> s;
            long long h1 = 0, h2 = 0;
            for(char c : s) {
                h1 = (h1 * P1 + (c - 'a' + 1)) % MOD1;
                h2 = (h2 * P2 + (c - 'a' + 1)) % MOD2;
            }
            hashes.insert({h1, h2});
        }
        for(int i=0; i<m; i++) {
            string s; cin >> s;
            long long h1 = 0, h2 = 0;
            vector<long long> p1(s.size() + 1, 1), p2(s.size() + 1, 1);
            for(size_t j=0; j<s.size(); j++) {
                h1 = (h1 * P1 + (s[j] - 'a' + 1)) % MOD1;
                h2 = (h2 * P2 + (s[j] - 'a' + 1)) % MOD2;
                if(j > 0) {
                    p1[j] = (p1[j-1] * P1) % MOD1;
                    p2[j] = (p2[j-1] * P2) % MOD2;
                }
            }
            p1[s.size()] = (p1[s.size()-1] * P1) % MOD1;
            p2[s.size()] = (p2[s.size()-1] * P2) % MOD2;
            
            bool found = false;
            long long pb1 = 1, pb2 = 1;
            for(int j=(int)s.size()-1; j>=0; j--) {
                for(char c='a'; c<='c'; c++) {
                    if(c != s[j]) {
                        long long nh1 = (h1 - (s[j] - 'a' + 1) * pb1 % MOD1 + MOD1) % MOD1;
                        nh1 = (nh1 + (c - 'a' + 1) * pb1) % MOD1;
                        long long nh2 = (h2 - (s[j] - 'a' + 1) * pb2 % MOD2 + MOD2) % MOD2;
                        nh2 = (nh2 + (c - 'a' + 1) * pb2) % MOD2;
                        if(hashes.count({nh1, nh2})) {
                            found = true;
                            break;
                        }
                    }
                }
                if(found) break;
                pb1 = (pb1 * P1) % MOD1;
                pb2 = (pb2 * P2) % MOD2;
            }
            cout << (found ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    if(cin >> n >> k) {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        vector<int> primes;
        for(int i=2; i<=n; i++) {
            if(is_prime[i]) {
                primes.push_back(i);
                for(int j=2*i; j<=n; j+=i) is_prime[j] = false;
            }
        }
        int count = 0;
        for(int i=2; i<=n; i++) {
            if(is_prime[i]) {
                bool found = false;
                for(size_t j=0; j+1<primes.size(); j++) {
                    if(primes[j] + primes[j+1] + 1 == i) {
                        found = true;
                        break;
                    }
                }
                if(found) count++;
            }
        }
        if(count >= k) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

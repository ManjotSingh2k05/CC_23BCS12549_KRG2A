#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    long long ans = 0;

    for(int bit = 0; bit < 32; bit++){
        long long count1 = 0;
        for(int i = 0; i < n; i++){
            if(a[i] & (1LL << bit))
                count1++;
        }
        long long count0 = n - count1;
        ans += count1 * count0;
    }

    cout << ans;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for(int i = 0; i < n; i++) cin >> words[i];

    vector<vector<int>> adj(26);
    vector<int> indeg(26,0);

    for(int i = 0; i < n-1; i++){
        string a = words[i];
        string b = words[i+1];

        int len = min(a.size(), b.size());
        bool found = false;

        for(int j = 0; j < len; j++){
            if(a[j] != b[j]){
                adj[a[j]-'a'].push_back(b[j]-'a');
                indeg[b[j]-'a']++;
                found = true;
                break;
            }
        }

        if(!found && a.size() > b.size()){
            cout << "Impossible";
            return 0;
        }
    }

    queue<int> q;
    for(int i = 0; i < 26; i++){
        if(indeg[i] == 0) q.push(i);
    }

    string ans = "";

    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans += char(node + 'a');

        for(int v : adj[node]){
            indeg[v]--;
            if(indeg[v] == 0)
                q.push(v);
        }
    }

    if(ans.size() != 26)
        cout << "Impossible";
    else
        cout << ans;
}
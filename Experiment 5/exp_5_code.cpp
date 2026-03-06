    #include <bits/stdc++.h>
    using namespace std;
     
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
     
        const long long p = 31;
        const long long mod1 = 1000000007;
        const long long mod2 = 1000000009;
     
        int n,m;
        cin>>n>>m;
     
        vector<long long> p1(600001), p2(600001);
        p1[0]=p2[0]=1;
     
        for(int i=1;i<=600000;i++){
            p1[i]=(p1[i-1]*p)%mod1;
            p2[i]=(p2[i-1]*p)%mod2;
        }
     
        unordered_set<long long> st;
     
        auto combine=[&](long long a,long long b){
            return (a<<32)^b;
        };
     
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
     
            long long h1=0,h2=0;
     
            for(int j=0;j<s.size();j++){
                int v=s[j]-'a'+1;
                h1=(h1+v*p1[j])%mod1;
                h2=(h2+v*p2[j])%mod2;
            }
     
            st.insert(combine(h1,h2));
        }
     
        while(m--){
            string s;
            cin>>s;
     
            long long h1=0,h2=0;
     
            for(int j=0;j<s.size();j++){
                int v=s[j]-'a'+1;
                h1=(h1+v*p1[j])%mod1;
                h2=(h2+v*p2[j])%mod2;
            }
     
            bool ok=false;
     
            for(int i=0;i<s.size();i++){
                for(char c='a';c<='c';c++){
                    if(c==s[i]) continue;
     
                    long long nh1=(h1-(s[i]-'a'+1)*p1[i])%mod1;
                    if(nh1<0) nh1+=mod1;
                    nh1=(nh1+(c-'a'+1)*p1[i])%mod1;
     
                    long long nh2=(h2-(s[i]-'a'+1)*p2[i])%mod2;
                    if(nh2<0) nh2+=mod2;
                    nh2=(nh2+(c-'a'+1)*p2[i])%mod2;
     
                    if(st.count(combine(nh1,nh2))){
                        ok=true;
                        break;
                    }
                }
                if(ok) break;
            }
     
            cout<<(ok?"YES\n":"NO\n");
        }
    }
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adjlist[n];
        for(int i=0;i<flights.size();i++){
            adjlist[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        vector<int> dist(n,INT_MAX);
        dist[src]=0; 
        queue<pair<int,pair<int,int>>> q; 
        q.push({0,{0,src}});
        while(!q.empty()){
            auto ele=q.front();
            q.pop();
            int stops=ele.first;
            if(stops > k) continue; 
            int d=ele.second.first;
            int node=ele.second.second;
            for(auto it:adjlist[node]){
                int v=it.first,wt=it.second;
                if(d+wt <dist[v]) {
                    dist[v]=d+wt;
                    q.push({stops+1,{dist[v],v}});
                }
            }
        }
        return dist[dst]==INT_MAX  ? -1 : dist[dst] ;
    }
};
#include<bits/stdc++.h>
using namespace std;

int main(){

    int V = 4;
    vector<vector<int>> dist = {
        {0,5,INT_MAX,10},
        {INT_MAX,0,3,INT_MAX},
        {INT_MAX,INT_MAX,0,1},
        {INT_MAX,INT_MAX,INT_MAX,0}
    };

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){

                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }

            }
        }
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}
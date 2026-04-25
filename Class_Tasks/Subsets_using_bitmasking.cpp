#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {

    int n = nums.size();
    vector<vector<int>> ans;

    for(int mask=0; mask<(1<<n); mask++) {

        vector<int> subset;

        for(int i=0;i<n;i++) {
            if(mask & (1<<i)) {
                subset.push_back(nums[i]);
            }
        }

        ans.push_back(subset);
    }

    return ans;
}

int main(){

    vector<int> nums={1,2,3};

    vector<vector<int>> ans=subsets(nums);

    for(auto v:ans){
        for(int x:v) cout<<x<<" ";
        cout<<endl;
    }
}
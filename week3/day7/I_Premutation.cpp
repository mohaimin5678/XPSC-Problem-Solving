#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> v(n,vector<int> (n-1));
        map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                cin>>v[i][j];
                if(j==n-2){
                    mp[v[i][j]]++;
                }
            }
        }
        int target,last;
        for( auto [x,y]:mp){
            if(y==1) target=x;  //occurance is unique
            else last=x;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(v[i][n-2]==target){
                for(int j=0;j<n-1;j++){
                    ans.push_back(v[i][j]);
                }
            }
        }
        ans.push_back(last);
        for(int x:ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
logic:
orders gular last value jetar unique, shetai initially
n-1 place niye nibe & jeta unique na sheta last e boshbe. 
*/
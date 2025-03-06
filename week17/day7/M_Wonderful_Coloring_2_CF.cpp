#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]].push_back(i);
    }
    // for(auto [x,y]:mp){
    //     cout<<x<<" --> ";
    //     for(int i=0;i<y.size();i++){
    //         cout<<y[i]<<" ";
    //     }
    //     cout<<ln;
    // }
    vector<int> idx;
    vector<int> ans(n);
    for(auto [x,y]:mp){
        int a=1;
        if(y.size()>=k){
            for(int i=0;i<k;i++){
                ans[y[i]]=a;
                a++;
            }
            for(int i=k;i<y.size();i++){
                ans[y[i]]=0;
            }
        }
        else{
            for(int i=0;i<y.size();i++){
                idx.push_back(y[i]);
            }
        }
    }
    int col=1;
    for(int i=0;i<idx.size()-(idx.size()%k);i++){
        if(col>k) col=1;
        ans[idx[i]]=col;
        col++;
    }
    for(int x:ans) cout<<x<<" ";
    cout<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        mohaimin();
    }
}
/*
since we can't put a specific color on same number twice so we can only
put colors on K amount of a specific number. So that each color can only
put once on a number. 
if there are more than K amount for a specific number, others will get 
0. 
if there are lower than K amounts then we'll take all of them into a
since vector & then serial wise put a color on to them. BUT this loop
will only run until we reach vector size-reminder of vector size by K. 
why? cause we need to put colors equally so that every colors get equal
numbers. 

adjacency list is not needed. Map is enough to solve this problem. 
*/
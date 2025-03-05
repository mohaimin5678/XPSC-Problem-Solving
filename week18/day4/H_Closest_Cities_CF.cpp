#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> forwrd,backwrd;
    for(int i=0;i<n-1;i++){
        if(i==0) forwrd.push_back(1);
        else{
            if(abs(v[i]-v[i+1]) < abs(v[i]-v[i-1])){
                forwrd.push_back(1);
            }
            else forwrd.push_back(abs(v[i]-v[i+1]));
        }
    }
    for(int i=n-1;i>0;i--){
        if(i==n-1) backwrd.push_back(1);
        else{
            if(abs(v[i]-v[i-1]) < abs(v[i]-v[i+1])) backwrd.push_back(1);
            else backwrd.push_back(abs(v[i]-v[i-1]));
        }
    }
    // for(int x:forwrd) cout<<x<<" ";
    // cout<<ln;
    // for(int x:backwrd) cout<<x<<" ";
    // cout<<ln;
    reverse(backwrd.begin(),backwrd.end());
    vector<ll> forcost;
    forcost.push_back(0);
    for(int i=0;i<forwrd.size();i++){
        if(i==0) forcost.push_back(forwrd[i]);
        else forcost.push_back(forwrd[i]+forcost.back());
    }
    // for(int x:forcost) cout<<x<<" ";
    // cout<<ln;
    vector<ll> backcost(n);
    for(int i=n-1;i>=0;i--){
        if(i==n-1) backcost[i]=0;
        else{
            backcost[i]=backwrd[i]+backcost[i+1];
        }
    }
    // for(int x:backcost) cout<<x<<" ";
    // cout<<ln;
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        x--,y--;
        if(x<y){
            cout<<forcost[y]-forcost[x]<<ln;
        }
        else cout<<backcost[y]-backcost[x]<<ln;
    }
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
to check them we'll check forward cost & it's prefix sum ALSO backward
cost & its suffix sum. 
for backward cost, we need to reverse the cost vector before calculating
it's suffix sum. 
then we'll take queries & convert them into 0-base indexing. 
then just calculate based on forward going or backward going. 
*/
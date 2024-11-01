#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    
    int mx=INT_MIN;
    for(auto [x,y]:mp){
        mx=max(mx,y);
    }
    cout<<mx<<'\n';
    
    return 0;
}
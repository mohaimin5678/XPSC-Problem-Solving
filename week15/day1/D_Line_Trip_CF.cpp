#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,d;
    cin>>n>>d;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        if(i==0){
            mx=max(mx,(v[i]-0));
        }
        else{
            mx=max(mx,(v[i]-v[i-1]));
        }
    }
    mx=max(mx,(d-v[n-1])*2);
    cout<<mx<<ln;
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
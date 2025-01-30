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
    map<int,int> dif;
    while(n--){
        int l,r;
        cin>>l>>r;
        dif[l]++;
        dif[r+1]--;
    }
    ll sum=0;
    ll mx=INT_MIN;
    for(auto [x,y]:dif){
        sum+=y;
        mx=max(sum,mx);
    }
    cout<<mx<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mohaimin();
}
/*
same approach as B number Two Tvs
*/
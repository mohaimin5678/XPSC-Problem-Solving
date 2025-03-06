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
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    if(n==1 || n==2){
        cout<<-1<<ln;
        return;
    }
    int idx=-1,mx=INT_MIN;
    ll sum=0;
    for(int i=0;i<n;i++){
        if(mx<v[i]){
            idx=i;
            mx=v[i];
        }
        sum+=v[i];
    }
    auto check=[&](ll x){
        vector<ll> a=v;
        a[idx]+=x;
        double sum2=sum+x;
        double avg=sum2/n;
        avg/=2;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]<avg) cnt++;
        }
        return cnt>(n/2);
    };
    ll l=0,r=1e12,mid,ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<ln;
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
used double to check floating values which helped to find the accurate
answer. Also since v[i] can be up to 10^6, extra gold pot can highest
take 10^12 cause 10^6+10^12=10^18 and we can't go beyond that. 
so using binary search on answer was a good practice cause tutorial 1-2
used a mathematical way to solve this. 
*/
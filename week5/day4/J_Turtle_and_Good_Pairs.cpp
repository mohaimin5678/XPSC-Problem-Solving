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
        ll n;
        cin>>n;
        string s;
        cin>>s;
        map<char,ll> mp;
        for(ll i=0;i<n;i++){
            mp[s[i]]++;
        }
        priority_queue<pair<ll,char>> pq;
        for(auto [x,y]:mp){
            pq.push({y,x});
        }
        string ans(n,'0');
        ll idx=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            ll cnt=p.first;
            char c=p.second;
            while(cnt--){
                if(idx>=n) idx=1;
                ans[idx]=c;
                idx+=2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
basically target is not to put duplicate char side by side
lets count frequency & sort them into descending order
simulation:
6
turtle
freq: e=1    l=1    r=1   t=2    u=1
inside pq:  2,t     1,u     1,r     1,l     1,e

now inside ans string using the while loop with initial idx=0: 
idx=0 so ans[0]=t & idx+=2    ans=[t-----]
idx=2 so ans[2]=t & idx+=2    ans=[t-t---] (t is done)
idx=4 so ans[4]=u & idx+=2    ans=[t-t-u-] (u is done)
idx>=6 so ans[1]=r & idx+=2   ans=[trt-u-] (r is done)
idx=3 so ans[3]=l & idx+=2    ans=[trtlu-] (l is done)
idx=5 so ans[5]=l & idx+=2    ans=[trtlue] (e is done)
hence our ans is now ready & pq also empty!
*/
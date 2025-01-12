#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    map<tuple<ll,ll,ll>,ll> mp;
    ll cnt=0;
    for(int i=0;i<n-2;i++){
        cnt+=(mp[{-1,v[i+1],v[i+2]}]+mp[{v[i],-1,v[i+2]}]+mp[{v[i],v[i+1],-1}] - 3*mp[{v[i],v[i+1],v[i+2]}]);
        mp[{-1,v[i+1],v[i+2]}]++;
        mp[{v[i],-1,v[i+2]}]++;
        mp[{v[i],v[i+1],-1}]++;
        mp[{v[i],v[i+1],v[i+2]}]++;
    }
    cout<<cnt<<endl;
    
    //brute force way
    // vector<pair<vector<int>,bool>> p(n-2);
    // for(int i=0;i<n-2;i++){
    //     p[i].first={v[i],v[i+1],v[i+2]};
    //     p[i].second=false;
    // }
    // for(int i=0;i<p.size();i++){
    //     int total=0;
    //     if(p[i].second!=true){
    //         for(int j=i+1;j<p.size();j++){
    //             if(p[i].first[0]!=p[j].first[0]) total++;
    //             if(p[i].first[1]!=p[j].first[1]) total++;
    //             if(p[i].first[2]!=p[j].first[2]) total++;

    //             if(total==1){
    //                 cnt++;
    //                 p[i].second=true;
    //                 // p[j].second=true;
    //             }
    //             total=0;
    //         }
    //     }
        
    //     // cout<<endl;
    // }
    // cout<<cnt<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) mohaimin();
    return 0;
}
/*
brute force: took all triplets into a vector & check if they are 
matching the condition or not. then count them & print them. 
but due to 2*10^5 contraint it went TLE. 

so we put all triplets into map. 
here we used tuple & triplet's count into map. 
we want to make pair among different triplet & thats our target. 
so suppose testcase: 
5
3 2 2 2 3
first we'll get [3 2 2] where we need [3 _ 2]/[_ 2 2]/[3 2 _] 
to make a pair with it. here _ means a different number. But since
we don't know which number, lets put -1 into those place. 
means for [3 2 2]-> [3 -1 2],[-1 2 2],[3 2 -1] will be counted AND
if we see we already found [3 2 2] then we need to remove it's 
contribution thrice. Why thrice? 
Because if we already got [3 2 2] before means these three 
[3 -1 2],[-1 2 2],[3 2 -1] will be calculated & provide us 3, but
we don't need this. Cause they are not unique. So if we find a triplet
that already occured then we'll remove it's occurance*3 from the answer. 

lets see step by step: 
5
3 2 2 2 3
for 3 2 2,
[-1 2 2]=0, [3 -1 2]=0, [3 2 -1]=0 also [3 2 2]=0 
so ans+=(0+0+0-3*0)=0;
[-1 2 2]=1, [3 -1 2]=1, [3 2 -1]=1 also [3 2 2]=1

for 2 2 2,
[-1 2 2]=1, [2 -1 2]=0, [2 2 -1]=0 also [2 2 2]=0
so ans+=(1+0+0-3*0)=1
[-1 2 2]=2, [2 -1 2]=1, [2 2 -1]=1 also [2 2 2]=1

for 2 2 3,
[-1 2 3]=0, [2 -1 3]=0, [2 2 -1]=1 also [2 2 3]=0
so ans+=(0+0+1-3*0)=2
*/
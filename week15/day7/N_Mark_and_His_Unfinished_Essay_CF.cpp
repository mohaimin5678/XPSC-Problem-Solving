#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    ll n,q,m;
    cin>>n>>q>>m;
    string s;
    cin>>s;
    vector<pair<ll,ll>> op(q),range(q);
    ll cur=n;
    for(int i=0;i<q;i++){
        ll x,y;
        cin>>x>>y;
        op[i]={x,y};
        ll cnt=y-x+1;
        range[i]={cur+1,cur+cnt};
        cur=range[i].second;
    }
    while(m--){
        ll v;
        cin>>v;
        if(v<=n){
            v--;
            cout<<s[v]<<ln;
            continue;
        }
        for(int i=q-1;i>=0;i--){
            if(v>=range[i].first && v<=range[i].second){
                v=(op[i].first)+(v-range[i].first);
            }
        }
        v--;
        cout<<s[v]<<ln;
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
tried the most common way which was substr & obviously it gave MLE. 
so I checked algobot to solve this problem. 
I used 2 pairs vector to solve this. on op vector I saved all 
operations & on range vector I saved the range that added to the
string after performing the operation. 
then for every index, I traversed on the reverse order of range
vector & checked which range has the index. then I set the index
as it's relevant operation pair's first index + (index-range's first value)
because it provided me a new index which had the same character.  
Now lets check the solution approach with a testcase--- 
testcase 1: 
4 3 3
mark
1 4
5 7
3 8
1
10
12

now: 
   op[0]={1,4}        op[1]={5,7}          op[2]={3,8}
range[0]={5,8}     range[1]={9,11}      range[2]={12,17}

m=0 & v=1 since v<=n(4) so s[v-1]=s[1-1]=s[0]=m
m=1 & v=10  now v is not in range[2]={12,17} so lets check lower
    v is in range[1]={9,11} so v=op[1].first + v-range[1].first
                               v=5+(10-9)=6
    v is in range[0]={5,8} so v=op[0].first + v-range[0].first
                              v=1+(6-5)=2
    v=2 so s[v-1]=s[2-1]=s[1]=a
m=2 & v=12  now v is in range[2]={12,17} so v=op[2].f + v-range[2].f 
                                            v=3+12-12=0
            now is not in range[1]={9,11} so lets check lower
            now is not in range[0]={5,8} so lets check lower
    v=3 so s[v-1]=s[3-1]=s[2]=r

so for m=0 answer m
       m=1 answer a
       m=2 answer r


*/
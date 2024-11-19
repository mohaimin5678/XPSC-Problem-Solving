#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    map<int,int> mp;
    int l=0,r=0;
    ll ans=0,unique=0;
    while(r<n){
        mp[v[r]]++;

        if(mp[v[r]]==1) unique++;

        while(unique>k){
            mp[v[l]]--;
            if(mp[v[l]]==0) unique--;
            l++;
        }
        ans+=(r-l+1);
        r++;
    }
    // cout<<endl;
    cout<<ans<<endl;
    return 0;
}
/*
2 6 4 3 6 8 3
process:
r=0 v[0]=2
mp=[2]
unique:1
ans+= (r-l+1)--> (0-0+1) so ans=1

r=1 v[1]=6
mp=[2,6]
unique:2
ans+= (r-l+1)--> (1-0+1) so ans+=2 so ans=3

r=2 v[2]=4
mp=[2,6,4]
unique:3
ans+= (r-l+1)--> (2-0+1) so ans+=3 so ans=6

r=3 v[3]=3
mp=[2,6,4,3]
unique:4>3(k)
so mp[v[l]]--; means mp[2]--;
since mp[v[l]]==0 means mp[2]==0 so unique--; now unique=3 & l=1
new mp=[6,4,3]
ans+= (r-l+1)--> (3-1+1) so ans+=3 so ans=9

r=4 v[4]=6
mp=[6,4,3]
unique:3
ans+= (r-l+1)--> (4-1+1) so ans+=4 so ans=13

r=5 v[5]=8
mp=[6,4,3,8]
unique:4>3(k)
so mp[v[l]]--; means mp[6]--; now mp[6]=1; now unique=4 & l=2
so mp[v[l]]--; means mp[4]--; now mp[4]=0; now unique=3 & l=3
new mp=[6,3,8]
unique:3
ans+= (r-l+1)--> (5-3+1) so ans+=3 so ans=16

r=6 v[6]=3
mp=[6,3,8]
unique:3
ans+= (r-l+1)--> (6-3+1) so ans+=4 so ans=20
*/
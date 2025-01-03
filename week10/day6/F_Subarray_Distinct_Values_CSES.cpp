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
    for(int i=0;i<n;i++) cin>>v[i];
    map<int,int> mp;
    int l=0,r=0;
    ll cnt=0;
    
    while(r<n){
        mp[v[r]]++;
        while(mp.size()>k){
            //the moment we get >k we'll remove left's contribution
            //until it comes back to <=k. then we'll increment l's index
            mp[v[l]]--;
            if(mp[v[l]]==0){
                auto it=mp.find(v[l]);
                mp.erase(it);
            }
            l++;
        }
        cnt+=(r-l+1);
        r++;
    }
    
    if(k==0) cnt=0;
    cout<<cnt<<endl;
    return 0;
}
/*
5 2
1 2 3 1 1

target is to find the number of subarrays with atmost k distinct values. 
now to find it lets approach this way: 
for {1} we'll get only 1 subarray which is {1}.          0+1=1
for {1,2} we'll get 2 subarrays which are {1,2},{2}.     1+2=3
then we got {1,2,3} so lets delete 1 from there. now,
for {2,3} we'll get 2 subarrays which are {2,3},{3}.     3+2=5
then we got {2,3,1} so lets delete 2 from there. now,
for {3,1} we'll get 2 subarrays which are {3,1},{1}.     5+2=7
for {3,1,1} we'll get 3 subarrays--> {3,1,1},{1,1},{1}.  7+3=10 

so lets go through this process:- 
r=0 v[r]=1
mp=[ 1:1 ] sz<k so no while loop triggered
cnt=0+(r-l+1)=0+(0-0+1)=1

r=1 v[r]=2
mp=[ 1:1  2:1 ] sz==k so no while loop triggered
cnt=1+(r-l+1)=1+(1-0+1)=1+2=3

r=2 v[r]=3
mp=[ 1:1  2:1  3:1 ] sz>k so while loop triggered 
so mp[v[l]]=mp[1]-- so mp[1]==0 so erase it from mp & now l=1
cnt=3+(r-l+1)=3+(2-1+1)=3+2=5

r=3 v[r]=1
mp=[ 2:1  3:1  1:1 ] sz>k so while loop triggered 
so mp[v[l]]=mp[2]-- so mp[2]==0 so erase it from mp & now l=2
cnt=5+(r-l+1)=5+(3-2+1)=5+2=7

r=4 v[r]=1
mp=[ 3:1  1:2 ] sz==k so no while loop triggered
cnt=7+(r-l+1)=7+(4-2+1)=7+3=10
*/
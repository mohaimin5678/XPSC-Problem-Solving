#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v(n),b(m);
    for(int i=0;i<n;i++) cin>>v[i];
    map<int,int> req,check;
    for(int i=0;i<m;i++){
        cin>>b[i];
        req[b[i]]++;
    }
    int cnt=0,res=0;
    for(int i=0;i<m;i++){
        check[v[i]]++;
        if(req[v[i]]!=0 && check[v[i]]<=req[v[i]]) cnt++;
    }
    if(cnt>=k) res++;
    for(int l=1,r=m;r<n;l++,r++){
        //contribution remove
        check[v[l-1]]--;
        if(req[v[l-1]]!=0 && check[v[l-1]]<req[v[l-1]]) cnt--;

        //current process
        check[v[r]]++;
        if(req[v[r]]!=0 && check[v[r]]<=req[v[r]]) cnt++;
        if(cnt>=k) res++;
    }
    cout<<res<<ln;
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
even if we tries to use 2 pointers (sliding window) naively, it'll 
give us TLE!
so we need to use them into a different way. 
first we'll take a map & count the B array's frequency. (req map)
then we'll take first M size from A array & to check it's frequency
on every running operation, we'll use another map(check).
so whats happening there? 
for the first M size of A, we are doing these:- 
1) check[v[i]]++; (counting it)
2) req[v[i]]!=0 (checking that if this element is required or not if 
                its not then false & next. Else check next condition)
3) check[v[i]]<=req[v[i]] (if the element's count is <= required then
                          we'll take it. Because element is required &
                          it's frequency is on limitation so we'll take
                          it. Now why we're doing this? Suppose we need
                          two 4 according to B. But we have three on check
                          map. then we won't count the 3rd 4 because its 
                          not on the limit.) 

after counting first m size elements, we'll check count>=k. if yes then
this particular subsegment is contributing on the answer. because we need
atleast k. 

then we'll start the 2 pointers where left=1 & right=m
why? because we already checked (0 to m-1) subsegment. 

then we'll remove l-1 index's contribution & check if its on the required
map. if it is, then check if its count<required's count. if it is, then
we need to decrement the cnt because we removed a required element. 

then we'll add r index's contribution & check if its on the required map.
if it is, then check if its count<=required's count. if it is, then we
will take it by incrementing the cnt because we've just added a required
element on the segment. 

after this 2 operation we'll check if the cnt>=k. if it is then it'll
contribute on the result. 
so here we just removed a value before left & added right, which keeps
our subsegment size equal to M. And we're doing this loop which is costing
O(N) complexity. 
*/

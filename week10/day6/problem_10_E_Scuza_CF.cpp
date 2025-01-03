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
        int n,q;
        cin>>n>>q;
        vector<int> v(n);
        vector<ll> pre(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(i==0) pre[i]=v[i];
            else pre[i]=pre[i-1]+v[i];
        }
        int maxx=INT_MIN;
        vector<int> mx(n);
        for(int i=0;i<n;i++){
            maxx=max(maxx,v[i]);
            mx[i]=maxx;
        } 
        // for(int x:mx) cout<<x<<" ";
        while(q--){
            int k;
            cin>>k;
            int l=0,r=n-1,mid;
            ll ans=0;
            while(l<=r){
                mid=(l+r)/2;
                if(mx[mid]<=k){
                    ans=pre[mid];
                    l=mid+1;
                }
                else r=mid-1;
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
we need to find with the leg height of k, how many stairs we can go
through & what will be our height after reaching our highest stair.
for example: 
4 5
1 2 1 5
1 2 4 9 10
here for k=1,
we can reach up only 1st stair so answer is 1
for k=2,
we can reach up to 3rd stair cause 1,2,1 are the stair's height. 
so answer is 1+2+1=4
for k=4, 
we can reach up to 3rd stair cause 1,2,1 are the stair's height. 
so answer is 1+2+1=4
for k=9,
we can reach up to final stair cause all values are lower than k. 
so with this leg's height we can reach all stairs. so 1+2+1+5=9 answer. 
for k=10 the answer will be also 9. 

now we actually find that the number of stairs we can reach is based
on the maximum height of the stairs till that specific stair. 
To clearify that lets see this -> 1 2 1 5
here lets calculate max height--> 1 2 2 5
means if k's value is something & we need to know if we can go to a
specific stair, we need to check if the max height from 1 to specific
stair is <=k or not. If its <= then we can reach that stair. And when
we reach that stair, we can achieve the height of prefix sum of that 
stair & that will be the answer for that specific leg's height. 
we can solve this using binary search(cloest to the left). 
now lets check this testcase: 
4 5
1 2 1 5
1 2 4 9 10

        now: 1 2 1 5
max per idx: 1 2 2 5
 prefix sum: 1 3 4 9

for k=1, 
l=0,r=3 so mid=1 then mx[mid]=2>1(k) so r=mid-1=1-1=0
l=0,r=0 so mid=0 then mx[mid]=1==1(k) so ans=pre[mid]=pre[0]=1 & l=mid+1=1
l>r so loop break; ans=1

for k=2,
l=0,r=3 so mid=1 then mx[mid]=2==2(k) so ans=pre[mid]=pre[1]=3 & l=mid+1=2
l=2,r=3 so mid=2 then mx[mid]=2==2(k) so ans=pre[mid]=pre[2]=4 & l=mid+1=3
l=3,r=3 so mid=3 then mx[mid]=5>2(k) so r=mid-1=3-1=2
l>r so loop break; ans=4

for k=4, as same as k=2. 

for k=9,
l=0,r=3 so mid=1 then mx[mid]=2<9(k) so ans=pre[mid]=pre[1]=3 & l=mid+1=2
l=2,r=3 so mid=2 then mx[mid]=2<=9(k) so ans=pre[mid]=pre[2]=4 & l=mid+1=3
l=3,r=3 so mid=3 then mx[mid]=5<9(k) so ans=pre[mid]=pre[3]=9 & l=mid+1=4
l>r so loop break; ans=9

for k=10, as same as k=9
*/
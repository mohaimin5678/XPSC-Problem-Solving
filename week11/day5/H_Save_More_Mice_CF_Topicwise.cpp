#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;
    vector<int> v(k);
    for(int i=0;i<k;i++) cin>>v[i];
    sort(v.begin(),v.end(),greater<int>());
    auto check=[&](int amount){
        ll dis=0;
        for(int i=0;i<amount;i++){
            dis+=(n-v[i]);
        }
        return dis<n;
    };

    int l=0,r=k,mid,ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
            
        }
        else r=mid-1;
    }
    
    cout<<ans<<endl;
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
target is to maximize the mice saving so binary search on answer 
should be based on k. 

now lets make the vector on descending order. 
after that we'll pass a mid into check function & see to save
that amount of mice, how much distance those mouse have to cover. 
if they cover =>n then no ELSE yes;

example: 
10 6
8 7 5 4 9 4
lets sort them: 9 8 7 5 4 4

binary search:
l=0, r=6 so mid=3
inside check: 
total distance: (10-9)+(10-8)+(10-7)=6 <10 so true;
ans=3

l=4, r=6 so mid=5
inside check: 
total dis: (10-9)+(10-8)+(10-7)+(10-5)+(10-4)=17 > 10 so false;

l=4,r=4 so mid=4
inside check: 
total dis: (10-9)+(10-8)+(10-7)+(10-5)= 9==9 so false;

l=4,r=3 loop break;
*/
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    auto check=[&](ll sec){
        ll cnt=0;
        for(int i=0;i<n;i++){
            cnt+=(sec/v[i]);
            if(cnt>=t){
                return true;
            }
        }
        return false;
    };

    ll l=1,r=1e18,mid,ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
/*
for every mid we'll check if it returns true/false using the
check function which is a lemda function. 
based on this problem,
lowest can be 
1 1
1
where 1 machine takes 1 sec to make 1 product. so initial l=1
highest can be
1 10^9
10^9
where 1 machine takes 10^9 sec to make 1 product & they want
10^9 amounts of products so it will take 10^9 * 10^9 = 10^18
sec to make. so initial r=10^18. 

for each mid, check function takes O(N)
while whole binary search takes O(log10^18)
so full complexity O(N*log10^18)
*/
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;
    ll total=n*(2LL*k+(n-1))/2;

    int l=1,r=n,mid;
    ll ans=LLONG_MAX;
    while(l<=r){
        mid=l+(r-l)/2;
        ll checkSum=mid*(2LL*k+(mid-1))/2;
        ll x=abs(2*checkSum-total);
        ans=min(ans,x);
        if(2*checkSum<total){
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
    while(t--){
        mohaimin();
    }
    return 0;
}
/*
n numbers of sum with the dif=1 formula: n*(2*k+(n-1))/2;
in math k==a. (shomantor dhara)

first we calculated the total using formula. 
then inside this binary search we checked mid formula, then
we find the absolute difference & saved it. 
if the mid sum is < target then the answer will be on the right
so l=mid+1
if the mid sum is > target then the answer will be on the left
so r=mid-1
*/
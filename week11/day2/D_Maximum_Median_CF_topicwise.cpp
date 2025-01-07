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
    sort(v.begin(),v.end());

    auto check=[&](int median){
        ll cnt=0;
        for(int i=(n/2);i<n;i++){
            cnt+=(v[i]<median ? (median-v[i]) : 0);
        }
        return cnt<=k;
    };

    int l=1,r=2e9,mid,ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
/*
        suppose v=      1 2 3 4 4 5 7
   median per operations
for median 5=2                1 1 0 0
for median 6=5                2 2 1 0
for median 7=8                3 3 2 0
for median 8=12               4 4 3 1
for median 9=16               5 5 4 2
for median 10=20              6 6 5 3
lets see if k=13
mid=(l+r)/2=(5+10)/2=7 means for median 7 we need operation 8<k
so ans=7 & l=mid+1=8
mid=(l+r)/2=(8+10)/2=9 means for median 9 we need operation 16>k 
so ans=7 still & r=mid-1=8
mid=(l+r)/2=(8+8)/2=8 means for median 8 we need operation 12<k
so ans=8 & l=mid+1=9
since l>r so break; 

so this is how we do the binary search based on the answer. 
here l=1 according to the constraint. 
also k can be 10^9 & v[i] can be 10^9
so if they want to give us a vector where we have to do 10^9
times +1 to a value which is 10^9 also then highest median 
can be 10^9+10^9=2*10^9. 
*/
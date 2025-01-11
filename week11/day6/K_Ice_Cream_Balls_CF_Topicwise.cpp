#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<2<<endl;
        return;
    }
    auto check=[&](ll balls){
        ll types=(balls*(balls-1))/2;
        return types<=n;
    };
    ll l=1,r=1e10,mid,ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    ll val=(ans*(ans-1))/2;
    ans+=(n-val);
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
if we choose balls=4,
then from {1,2,3,4} we can make {1,2},{1,3},{1,4},{2,3},{2,4},{3,4}
in total=6 types. to calculate the types we can use a formula. 
which will provide the sum of n-1. formula: ((n-1)*n)/2 
so sum=(3*4)/2=6

suppose we wants to make n=7 types,
we can make 6 types using 4 balls. so extra we'll need 1 more
ball to make 7 types of icecream. 

again for n=9
we can make 6 types using 4 balls. so extra we'll need 3 more
balls to make 9. 

so using binary search we'll send mid value. & check function
will return the types amount. if the types amount is <=n then 
true. & we'll further check if its possible to makes more types
using right sided ball amount. And if check returns false, then
we have to find more lower ball amount to make <=types amount. 
Once we find the answer we have to check how many types the answer
amount can make. then we'll check how many types are left to make. 
for each remaining type, we'll be needed more balls. 

lets explain with N=9
check function will return 4
using 4 we can make 6 types. 
remaining types=9-6=3
so total balls needed=4+3=7. (final answer)
*/
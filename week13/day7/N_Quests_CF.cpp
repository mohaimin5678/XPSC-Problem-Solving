#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    ll n;
    ll c,d;
    cin>>n>>c>>d;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    sort(v.rbegin(),v.rend());
    ll total=0;
    for(ll i=0;i<min(n,d);i++){
        total+=v[i];
    }
    // cout<<ln;
    if(c<=total){
        cout<<"Infinity"<<ln;
        return;
    }
    auto check=[&](ll k){
        if(k==0){
            return (v[0]*d>=c);
        }
        ll sum=0,amount=(d/k);
        ll rem=d%k;
        for(ll i=0;i<min(n,k);i++){
            sum+=v[i];
            // if(sum>=c) return true;
        }
        sum*=amount;
        for(ll i=0;i<min(n,rem);i++){
            sum+=v[i];
            // if(sum>=c) return true;
        }
        return sum>=c;
    };

    ll l=0,r=2e5,mid,ans=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }

    if(ans==-1){
        cout<<"Impossible"<<ln;
        return;
    }
    cout<<--ans<<ln;
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
binary search on answer is the way to solve this after sorting
it by descending order. 
Lets handle the case of "Infinity" first:- 
if the minimum of (quests & days) amount of rewards is already
higher than C then the answer is Infinity. Cause the total of
those initial values (means taking them only once) is enough
to get over with the targeted points(C). So after that it doesn't
matter what will be the value of K, it will always get more than
the targeted points(C).

then lets start with the binary search on answer.
since K will be in between d's range so lets put l=0,r=2e5
and the binary search's target is to maximize the answer. 

now inside the check function:
(here K can be referred as Gap) 

1) if K becomes 0 that means we can only repeat the max value 
till d days. So if max*d >=C that will return true else false. 

2) we'll add into sum till we reach the min(n,k). Then we'll
multiply the amounts of a digit will be added which is (d/k).
Now why min(n,k)?
because suppose N=5, K=2, d=5 & we have v=[8 7 6 5 4]
means we'll take sum=8+7=15 & then sum*=2 so sum=30
means we are taking the highest 2 value twice. [8 7 8 7]
which is why we are taking the min(n,k).

3) Now if there is any remaining days left we need to add their
contribution on sum too. so now we'll check min(n,rem). 
so if n>rem then all values from vector will be added into sum 
else-> to fill up the remaining part, the remaining amounts of
values from vector will be added to sum. 

4)after these 2 loops & calculation, we'll just return sum>=C
if sum is >= than C means the value of K can make >= points. 
else it can't. 

but there is a small part we need to pay attention & for that
lets see a testcase:- 
5 38 5
8 7 6 5 4
here n=5, c=38, d=5
now if k=2,
then first loop will be till min(n,k)=2
so sum=0+v[0]+v[1]=0+8+7=15

now d/k=5/2=2 so sum*=2 ---> sum=30

rem=5%2==1
so add sum+=v[0] ---> sum=30+8=38
we took [8 7 8 7 8] to make 38 where 8 appears with 1 gap
now check function will return true 

but we send k=2 which should be the gap. But it turned out that
every gap amount we are sending, it working as gap-1. 
thats why k=2 but we are getting [8 7 8 7 8] where both 8 & 7
appearing with 1 gap only. 

Also if the answer is still -1 means no gap can took us to the
targeted point C. 
*/
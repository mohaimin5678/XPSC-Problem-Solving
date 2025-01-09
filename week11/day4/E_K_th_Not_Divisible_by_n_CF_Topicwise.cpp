#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;

    auto check=[&](int value){
        return (value-(value/n))>=k;
    };

    int l=1,r=2e9,mid,ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
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
for 3: 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
    x     x     x       x        x
1 2 4 5 7 8 10 11 13 14 16
1 2 3 4 5 6 7  8  9  10 11
it means how many non divisible numbers are there till that value.
for ex: value=14 so till 14 there are 14-4=10 values which are
non divisible by 3. 

if we use value-(value/3) it will always provide us the serial
number of that non divisible value.

lets suppose value=17
then 17-(17/3)=17-5=12 so there are 12 amount of numbers that
are not divisible by 3. And 12th number is 17. 

what if we pick a value which is divisible by 3?
suppose value=18
then 18-(18/3)=18-6=12 but we saw that 17 is already on that 
12th position. So all divisible value's positions will be taken
by all non divisible values. So all positions will indicate 
non-divisible value's position. 

now lets suppose: n=3 & k=7
l=1 & r=16
mid=1+(16-1)/2=1+7=8
inside check: value=8 so 8-(8/3)=8-2=6<k

so l=mid+1=9 & r=16
mid=9+(16-9)/2=9+3=12
inside check: value=12 so 12-(12/3)=12-4=8>k
so ans=12 & r=mid-1

so l=9 & r=11
mid=9+(11-9)/2=9+1=10
inside check: value=10 so 10-(10/3)=7==k
so ans=10 & r=mid-1

so l=9 & r=9
mid=9
inside check: value=9 so 9-(9/3)=6<k
so l=mid+1

so l=10 & r=9 loop break;
finally ans is 10. 

lowest will always be 1 so l=1
for highest, if they give us n=2 & they want us to provide the
10^9 th non divisible value of(k) then at least we have to
go to 2*10^9 to get the value of kth non divisible value. 
*/
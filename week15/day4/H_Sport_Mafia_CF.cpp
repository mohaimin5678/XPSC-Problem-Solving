#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    ll n,k;
    cin>>n>>k;
    if(n==1 && k==1){
        cout<<0<<ln;
        return;
    }
    auto check=[&](ll x){
        ll in=(x*(x+1))/2;
        ll out=n-x;
        if((in-out)<k) return -1;
        else if((in-out)>k) return 1;
        else return 0;
    };
    ll l=0,r=n,mid,ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)==0){
            ans=n-mid;
            break;
        }
        else if(check(mid)==1){
            r=mid-1;
        }
        else if(check(mid)==-1){
            l=mid+1;
        }
    }
    cout<<ans<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    while(t--){
        mohaimin();
    }
}
/*
used the binary search on answer & checked for which calculation
we are finding K. And the range is from 0 to n cause alya can
eat atmost n amounts of candies. 
since per move alya is putting previous+1 in the box so we can
separate 2 sections for N. 
1-> X moves for putting candies  2->N-X moves for eating candies
so for X moves alya can put x*(x+1)/2 amounts of candies
from there she can eat n-x amount of candies
so if remaining candies matches K then X is the total amount of
candies but they wants to know how many candies alya ate. So
the answer will be N-X which is N-mid in the binary search. 
*/

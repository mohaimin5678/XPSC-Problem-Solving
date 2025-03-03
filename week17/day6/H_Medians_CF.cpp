#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;
    if(n==1 && k==1){
        cout<<1<<ln<<1<<ln;
        return;
    }
    if(n>1 && (k==1 || k==n)){
        cout<<-1<<ln;
        return;
    }
    if(k%2==0){
        cout<<3<<ln;
        cout<<1<<" "<<k<<" "<<k+1<<ln;
    }
    else{
        cout<<3<<ln;
        cout<<1<<" "<<k-1<<" "<<k+2<<ln;
    }
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
if k==1 while n==1 then only 1 subarray possible & its 1 + answer is
also 1. 

if n>1 & k==1/n then its not possible to make a median from all subarray
so answer is -1. cause median will always stay in the middle not at
first/last. 

if n>1 & k is even then we need to create odd length subarrays. Now
all subarray's length don't need to be equal but definitely odd length. 
So we'll take [1 to k-1] , [k], [k+1 to n] as 3 subarrays. And we know
from there we can make K as our median. 

if n>1 & k is odd then again we need to create odd length subarrays. 
Now all subarray's length don't need to be equal but definitely odd 
length. So we'll take [1 to k-2] , [k-1,k,k+1], [k+2 to n] as 3 subarrays. 
And we know from there we can make K as our median.
this is how we can solve this. 
*/

#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
const int B=30;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<int> bits(B+1);
        for(int i=0;i<n;i++){
            for(int k=B;k>=0;k--){
                if((v[i]>>k)&1){
                    bits[k]++;
                }
            }
        }
        ll ans=0;
        for(int i=B;i>=0;i--){
            if(bits[i]==n){ //means all are on
                ans+=(1LL<<i);
            }
            else{
                int need=n-bits[i]; 
                //means how many needed to make all of them on
                if(k>=need){
                    ans+=(1LL<<i);
                    k-=need;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
for testcase 2:
7 5
4 6 6 28 6 6 12

    ..  64 32 16 8 4 2 1
4 -> ....0 0   0 0 1 0 0 
6 -> ....0 0   0 0 1 1 0 
6 -> ....0 0   0 0 1 1 0 
28-> ....0 0   1 1 1 0 0 
6 -> ....0 0   0 0 1 1 0 
6 -> ....0 0   0 0 1 1 0 
12-> ....0 0   0 1 1 0 0 
---------------------------- AND
     ....0 0   0 0 1 0 0=4 initially
here .... represents the other bits which are 0. 
here we can see that a bit can add into the answer when that
bit is on in all element. So to increase the answer, out target
will be the possible highest valued bit. If we can make that bit
1 for all element then it will contribute & it will definitely
increase the answer. 
like our priority will be: 30th bit>29th bit>28th bit>27th bit...

on the bits vector, we took all the on bit's numbers. 
since we can only use 5 operation, we can't use 30th to 4th bits.
because from 30th to 5th, to make all of them 1, we'll need 7
operations. And to make all of them 1 in 4th bit, we'll need 6
operations. Since k=5, we can see that in 3rd bit there is 5 
operations needed to make all of them 1. So we can add the 3rd
bit's contribution into the answer which is 8 & 2nd bit was 
already 1 for all element so we'll also add this into answer. 
so final answer: 12
*/
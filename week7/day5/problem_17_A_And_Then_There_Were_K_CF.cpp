#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int msBit=__lg(n);
        int ans=(1<<msBit);
        ans--;
        cout<<ans<<endl;
    }
    return 0;
}
/*
instead of bruteforce, lets see 
n=5 --> 101
n=4 --> 100
------------ AND
        100 = 4
n=3 --> 011 
------------ AND
        000 = 0

so we can clearly see that any n's (msb & (msb-1))==0
so we just have to find the msb, then take the value of (1<<msBit)
then just decrement it by one. Which will be the answer. 
*/
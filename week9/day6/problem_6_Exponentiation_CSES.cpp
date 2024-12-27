#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
const int MOD = 1e9+7;
int power(int x,int n){
    int ans=1%MOD;
    while(n){
        if(n&1){
            ans=(1LL*ans%MOD * x%MOD)%MOD;
            //before executing outer MOD, the value can overflow
            //inside the first bracket, so 1LL can handle the overflow
        }
        x=1LL* x*x %MOD;
        n>>=1;      // n/=2; same meaning
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<power(a,b)<<endl;
    }
    return 0;
}
/*
here we used Binary exponentiation. Where we check b's bits and
then we made our decision. 
suppose testcase: 
3 11
a=3 & b=11
b's bit expression: 1101 (1 2 4 8 -->)
inside function: 
first:
    ans=1
    b=11
    inside if cause 0th bit on--> ans=1*a = 1*3 = 3
    a=a*a=3*3=9
    b=5
second: 
    ans=3
    b=5
    inside if cause 1st bit on--> ans=3*a = 3*9 = 27
    a=a*a=9*9=81
    b=2
third: 
    ans=27
    b=2
    Not inside if cause 2nd bit off. 
    a=a*a=81*81=6561
    b=1
forth: 
    ans=27
    b=1
    inside if cause 3rd bit on--> ans= 27*a = 27*6561 = 177147
    a=a*a=6561*6561=43046721
    b=0
since b is 0 so while loop break;
return 177147

now,
we used (b&1) to check if the right most bit of b is on or not. 

also in ans=(1LL*ans%MOD * x%MOD)%MOD;
we used 1LL to ignore the overflow if ans*x is bigger than int but
individually they are not big enough to MOD. So 1LL will not make
the overflow inside the first bracket, then we'll reduce it by
the MOD & it will sustain in int. 

also x=1LL* x*x %MOD;
here we powering up the x. 
suppose we already calculated 3^1 , then we will do 3^1*3^1=3^2
which will be use in next loop turn. again if x*x have a possibility
to overflow, MOD will make sure it doesn't happen. 
*/
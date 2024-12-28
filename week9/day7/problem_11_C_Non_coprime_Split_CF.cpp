#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int isPrime(int n){
    // if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return i;
    }
    return n;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        if(l<=3 && r<=3) cout<<-1<<endl;
        else if(l<r){
            if(r%2==0){
                cout<<r/2<<" "<<r/2<<endl;
            }
            else{
                r--;
                cout<<r/2<<" "<<r/2<<endl;
            }
        }
        else if(l==r){
            if(isPrime(r)==r){
                cout<<-1<<endl;
            }
            else{
                cout<<isPrime(r)<<" "<<r-isPrime(r)<<endl;
            }
        }
    }
    return 0;
}
/*
between {1,3} all values will give -1 because none can fill both
conditions. 
now when l<r,
means there is a range of few/more numbers. since a+b can be 
atmost r, we have to keep that in mind that the summation can't
go above r. How to keep that <=r ? we can take a=r/2 & b=r/2 
which can keep the summation <=r. Now if r is even then straight
r/2 & r/2. but if r is odd, then decrement r's value by 1 & then
do r/2 & r/2.

now if l==r,
check if the value is prime or not. if prime then no answer. 
else we'll get the divisor of that value which can be a & 
value-divisor can be b. 

ex: 
l=18 & r=18
18 is not prime so its first divisor is 2 which is a
so b=18-2=16
a+b==18<=r
gcd(2,16)=2 != 1
so this is the answer
*/
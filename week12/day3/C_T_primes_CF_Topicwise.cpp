#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
bool isPrime(ll n){
    if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
bool perfectSquare(ll n){
    ll x=sqrtl(n);  //sqrtl for ll values
    return (x*x==n);
}
void mohaimin(){
    int t;
    cin>>t;
    while(t--){
        ll val;
        cin>>val;
        if(perfectSquare(val) && isPrime(sqrtl(val))){
            cyes;
        }
        else cno;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mohaimin();
}
/*
They want us to print yes/no for every elements of the array,
if element has exactly 3 divisors.

suppose we have a value 18 --> 2^1 * 3^2 (prime factorization)
                     e1     e2    e3         en
we found out that: P1   * P2  * P3  *....* Pn
                =(e1+1)*(e2+1)*(e3+1)*....*(en+1)
so for 2^1 * 3^2,
no. of divisors: e1==1 & e2==2 so (1+1)*(2+1)=2*3=6
& 18's divisors are= 1 2 3 6 9 18 = 6 so formula is proven. 

so how this technique of using prime factorization will help
us to solve this problem?
Suppose we have: 7 = 7^1 = P1
    also another 7 = 7^1 = p1
now since we got 2 P1 & if its in a 7*7 situation, we can write
it like P1^2 == 7^2 == 49. 
Now 49's divisors are: 1 7 49. 
AGAIN,
Suppose we have: 5 = 5^1 = P1
    also another 5 = 5^1 = p1
now since we got 2 P1 & if its in a 5*5 situation, we can write
it like P1^2 == 5^2 == 25. 
Now 49's divisors are: 1 5 25.
if we observe this then we know both 5 & 7 are prime number.
so NOTE: only (prime number)^2 value have 3 amount of divisors.
Any other numbers doesn't have 3 amount of divisors. 

for 4 amount of divisors?
1-> all (prime number)^3 value have 4 amount of divisors.
EX: 125= 1,5,25,125
2-> prime1*prime2 multiplication value have 4 divisors.
EX: 5*7=35 so it's divisors: 1,5,7,35


so in this problem we'll first check if the given value is a
perfect square or not. 
Why? because our target is to check if it's sqrt value is prime
then it'll must have 3 divisors. But if the sqrt value has 
fraction then it won't provide us the accurate answer. So first
we need to check this.
then we need to check if the value's sqrt value is a prime or
not. Because if its a perfect square but it's sqrt value is not
prime then there will be more than 3 divisors exists. So 2ndly
we'll check this. 
if both conditions are satisfied then answer YES. Else NO.
*/

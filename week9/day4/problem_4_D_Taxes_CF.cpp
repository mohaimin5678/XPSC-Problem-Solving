#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
bool isPrime(int n){
    if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    if(isPrime(n)) cout<<1<<endl;       //for prime
    else if(n%2==0) cout<<2<<endl;      //for even
    else{
        if(isPrime(n-2)) cout<<2<<endl;     //for a prime odd
        else cout<<3<<endl;                 //for even->2 & for 3->1
    }
    return 0;
}
/*
Goldbach's conjecture--> every even number>2 can be present as the
sum of 2 prime numbers. 

Now they will give a value N, But we have to split the N into other
numbers so that those number's 2nd most divisor is minimum enough. 
Note: 2nd most divisor=1 for all prime numbers. 

Now scene 1: N=prime
--> no need to split as it's 2nd most divisor is already 1. 

scene 2: N=even
--> split it into 2 prime number(Goldbach's conjecture) and we'll
get 1 for each prime number. so 1+1=2. 

scene 3: N=odd
i) remove 2 from it & check if N-2 is a prime number or not. If it
is, then we'll get 1 for 2 and 1 for N-2(prime number). So 1+1=2. 
If upper condition doesn't satisfy then,
ii) remove 3 from it & it will become an even number. Then we can
split it into 2 prime number(Goldbach's conjecture) and we'll
get 1 for each prime number. So 1 for 3, 2 for N-3(even number).
answer= 1+2=3. 

so answer will always stay between 1,2,3. 
*/

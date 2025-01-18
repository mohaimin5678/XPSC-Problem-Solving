#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=1000009;
vector<int> allPrime;
void Sieve(){
    vector<bool> prime(maxN+1,true);
    for(int i=2;i*i<=maxN;i++){
        if(prime[i]){
            for(int j=i+i;j<=maxN;j+=i){   
                prime[j]=false;
            }
        }
    }
    for(int i=2;i<=maxN;i++){
        if(prime[i]){
            allPrime.push_back(i);
        }
    }
    
}
void mohaimin(){
    int d;
    cin>>d;
    //binary search
    // int l=0,r=allPrime.size()-1,mid1,ans1;
    // while(l<=r){
    //     mid1=l+(r-l)/2;
    //     if(allPrime[mid1]>=(1+d)){
    //         ans1=allPrime[mid1];
    //         r=mid1-1;
    //     }
    //     else l=mid1+1;
    // }
    // cout<<ans1<<" ";
    
    // int f=0,right=allPrime.size()-1,mid2,ans2;
    // while(f<=right){
    //     mid2=f+(right-f)/2;
    //     if(allPrime[mid2]>=(ans1+d)){
    //         ans2=allPrime[mid2];
    //         right=mid2-1;
    //     }
    //     else f=mid2+1;
    // }
    // cout<<ans1*ans2<<ln;


    //lower_bound
    auto it1=lower_bound(allPrime.begin(),allPrime.end(),1+d);
    int x=*it1;
    auto it2=lower_bound(allPrime.begin(),allPrime.end(),x+d);
    int y=*it2;
    cout<<x*y<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Sieve();
    int t; 
    cin>>t;
    while(t--){
        mohaimin();
    }
}
/*
Target is to solve the problem where they'll provide us D
as distance. 
we need to show them based on the given distance we can get
a number who has atleast 4 divisors. 
Now we already know that (prime)^3 has 4 divisors but 
the answer of prime1*prime2 also has 4 divisors!
ANd prime1*prime2 can also provide us the answer in minimum
D distance. How?
suppose distance is 2,
first divisor is always 1
next divisor should be 1+2=3 or more(if 3 isn't a divisor)
but 3 is a divisor so 3 is prime1
next divisor should be 3+2=5 or more(if 5 isn't a divisor)
but 5 is a divisor so 5 is prime2
now the answer is 3*5=15 because [1 3 5 15] has atleast 2
distance for all divisors. 
so to find prime1 & prime2 we can do binary search or we
can do lower bound too to find the answer.
*/
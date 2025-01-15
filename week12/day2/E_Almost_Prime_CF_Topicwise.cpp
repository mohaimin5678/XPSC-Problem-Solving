#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
const int maxN=3009;
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Sieve();
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        int x=i,cnt=0;
        for(int j=0;j<allPrime.size();j++){
            if(x<allPrime[j]) break;
            if(x%allPrime[j]==0) cnt++;
        }
        if(cnt==2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
/*
we'll collect all the prime nummbers till 3000. 
then for the input N, we'll check for each number till N that how 
many prime numbers can be it's divisors. if count of divisors=2 then
it will be added to the answer. 
*/
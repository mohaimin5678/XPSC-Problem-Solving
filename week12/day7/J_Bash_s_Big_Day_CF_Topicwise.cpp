#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
// const int maxN=1e5+5;
// vector<int> allPrime;
// void Sieve(){
//     vector<bool> prime(maxN+1,true);
//     for(int i=2;i*i<=maxN;i++){
//         if(prime[i]){
//             for(int j=i+i;j<=maxN;j+=i){   
//                 prime[j]=false;
//             }
//         }
//     }
//     for(int i=2;i<=maxN;i++){
//         if(prime[i]){
//             allPrime.push_back(i);
//         }
//     }
    
// }
void mohaimin(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    map<int,int> cnt;
    for(int i=0;i<n;i++){
        int x=v[i];
        for(int j=2;j*j<=x;j++){
            if(x%j==0) cnt[j]++;
            while(x%j==0){
                x/=j;
            }
        }
        if(x>1) cnt[x]++;
    }
    int mx=1;
    for(auto [x,y]:cnt){
        mx=max(y,mx);
    }
    cout<<mx<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // Sieve();
    mohaimin();
    
}
/*
Don't need Sieve cause it was giving TLE for a testcase. 
so to handle that, we checked the primes for individual values.
And it didn't give TLE because we were checking all primes till
that loop reach the srqt(value). 
so complexity became O(N*sqrt(N)). 
*/
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
vector<bool> prime(maxN+1,true);
void Sieve(){
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
    int n; cin>>n;
    vector<int> v;
    map<int,int> mp;
    for(int i=2; i<=n+1; i++){
        if(prime[i]){
            v.push_back(1);
            mp[1]++;
        }
        else{
            v.push_back(2);
            mp[2]++;
        }
    }
    cout<<mp.size()<<'\n';
    for(auto value:v){
        cout<<value<<" ";
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Sieve();
    mohaimin();
}
/*

*/
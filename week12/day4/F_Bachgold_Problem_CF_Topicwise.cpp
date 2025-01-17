#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=100009;
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
    int n;
    cin>>n;
    vector<int> ans;
    int i=0;
    
    if(n%2==0){
        for(int j=1;j<=n/2;j++){
            ans.push_back(2);
        }
    }
    else{
        n-=3;
        ans.push_back(3);
        for(int j=1;j<=n/2;j++){
            ans.push_back(2);
        }
    }
    
    cout<<ans.size()<<endl;
    for(int x:ans) cout<<x<<" ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Sieve();
    mohaimin();
    
}
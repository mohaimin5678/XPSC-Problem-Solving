#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
vector<int> allprimes={2,3,5,7,11,13,17,19,23,29,31};

void mohaimin(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<11;j++){
            if(v[i]%allprimes[j]==0){
                // mp[allprimes[j]].push_back(v[i]);
                mp[allprimes[j]].push_back(i);
                break;
            }
        }
    }
    
    // for(auto [a,b]:mp){
    //     cout<<a<<" --> ";
    //     for(auto x:b) cout<<x<<" ";
    //     cout<<ln;
    // }
    vector<int> ans(n);
    int color=1;
    for(auto [x,y]:mp){
        for(auto pos:y){
            ans[pos]=color;
        }
        color++;
    }
    cout<<mp.size()<<ln;
    for(int x:ans) cout<<x<<" ";
    cout<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        mohaimin();
    }
}
/*
we have to color an array where colors are from 1 to m(<=11). 
the conditions are: 
i) All colors from 1 to M must occurs atleast once. 
ii) No element will hold more than 1 color. 
ii) same color holding element's gcd>1 

observation: prime factorization is a solution approach for this
problem. We know the smallest prime is 2 & prime factorization
contributes on gcd also. So even if the smallest prime number
contributes on gcd then the gcd will obviously become >1. Cause
we're coloring same elements which are divisible by same prime. 
So we need to check which elements are divisible by same prime. 

Also since m<=11 & we can only works with first 11 prime numbers
& for every prime we'll give a color. 

map<int,vector<int>> mp;
using this we are saving the prime & the elements position which
are divisible by that prime. 
And then we are serially putting color in those positions. 

example: 
7
20 33 49 289 143 529 522

prime       values with index
2           20(0)   522(6)
3           33(1)
7           49(2)
11          143(4)
17          289(3)
23          529(5)

so we can see that 6 primes are enough to distribute the whole
array so colors will be also 6. 
so serially putting the color according to prime number: 
for 2->  ans=[1 _ _ _ _ _ 1] color++
for 3->  ans=[1 2 _ _ _ _ 1] color++
for 7->  ans=[1 2 3 _ _ _ 1] color++
for 11-> ans=[1 2 3 _ 4 _ 1] color++
for 17-> ans=[1 2 3 5 4 _ 1] color++
for 23-> ans=[1 2 3 5 4 6 1] color++
so final answer is: 
6
1 2 3 5 4 6 1
*/

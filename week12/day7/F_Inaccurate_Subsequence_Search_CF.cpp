#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    multiset<int> ml;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        ml.insert(x);
    }
    
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
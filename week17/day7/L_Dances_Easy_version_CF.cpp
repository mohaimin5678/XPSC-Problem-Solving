#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(n);
    for(int i=1;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    a[0]=m;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int l=0,r=0;
    int cnt=0;
    while(r<n){
        if(a[l]<b[r]){
            l++,r++;
        }
        else{
            r++;
            cnt++;
        }
    }
    cout<<cnt<<ln;
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
just push front m on vector a then sort both. 
checked a[i]<b[j] else increase b[j] & count the changes. 
*/
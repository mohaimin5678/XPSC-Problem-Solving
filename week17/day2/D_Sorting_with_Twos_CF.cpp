#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    vector<int> dif(n+1);
    for(int i=1;i<n;i++){
        dif[i]=v[i+1]-v[i];
    }
    // for(int i=1;i<n;i++){
    //     cout<<dif[i]<<" ";
    // }
    // cout<<ln;
    for(int i=1;i<n;i++){
        if(dif[i]<0){
            if((i&(i-1))!=0){   //checking if its power of 2 or not
                cno;
                return;
            }
        }
    }
    cyes;
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
checked difference array
if dif[i]<0 means descending order situation occurs, so we'll check
if the index is any value of 2^something. if it is then we can do
operations on it. but if it isn't then we can't select this as a
range so NO. 
*/
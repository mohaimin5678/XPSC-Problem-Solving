#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,x,y;
    cin>>n>>x>>y;
    
    while(x--){
        if(n<=(10*y)){
            cyes;
            return;
        }
        n/=2;
        n+=10;
    }
    n-=(10*y);
    
    if(n>0) cno;
    else cyes;
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
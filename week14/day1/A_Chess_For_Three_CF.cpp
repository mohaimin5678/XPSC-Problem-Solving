#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int a,b,c;
    cin>>a>>b>>c;
    int sum=a+b+c;
    if(sum%2==1){
        cout<<-1<<ln;
        return;
    }
    if(a+b<=c && c!=0){
        cout<<a+b<<ln;
        return;
    }
    int draws=sum/2;
    cout<<draws<<ln;
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
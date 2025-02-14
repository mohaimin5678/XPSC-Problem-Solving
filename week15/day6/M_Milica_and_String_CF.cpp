#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if(s[i]=='A') a++;
        else b++;
    }
    if(k==0 && b==n){
        cout<<1<<ln;
        cout<<n<<" A"<<ln;
        return;
    }
    if(k==b){
        cout<<0<<ln;
        return;
    }
    if(k>b){
        int target=k-b;
        int cnt=0;
        int i;
        for(i=0;i<n;i++){
            if(s[i]=='A') cnt++;
            if(cnt==target) break;
        }
        cout<<1<<ln;
        cout<<i+1<<" B"<<ln;
    }
    else{
        int target=b-k;
        int cnt=0;
        int i;
        for(i=0;i<n;i++){
            if(s[i]=='B') cnt++;
            if(cnt==target) break;
        }
        cout<<1<<ln;
        cout<<i+1<<" A"<<ln;
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
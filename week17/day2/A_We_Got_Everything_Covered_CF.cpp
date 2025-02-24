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
    char c='a';
    int sz=n*k;
    char v[sz];
    for(int i=0;i<k;i++){
        for(int j=i;j<sz;j+=k){
            v[j]=c;
        }
        c++;
    }
    for(char x:v) cout<<x;
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
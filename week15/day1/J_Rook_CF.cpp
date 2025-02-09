#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    char a,n;
    cin>>a>>n;
    for(char i='1';i<'9';i++){
        if(i!=n){
            cout<<a<<i<<ln;
        }
    }
    for(char i='a';i<='h';i++){
        if(i!=a){
            cout<<i<<n<<ln;
        }
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
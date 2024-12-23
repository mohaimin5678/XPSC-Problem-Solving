#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if(b==1) cout<<"NO"<<endl;
        else{
            ll x=a;
            ll y=a*b;
            ll z=a*(b+1);
            cout<<"YES"<<endl;
            cout<<x<<" "<<y<<" "<<z<<endl;
        }
    }
    return 0;
}
/*
a+(a*b)=a*(b+1)
*/
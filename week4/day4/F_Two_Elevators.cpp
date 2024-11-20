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
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==1) cout<<1<<endl;
        else{
            ll f=abs(a-1);
            ll s=abs(b-c)+(c-1);
            if(f<s) cout<<1<<endl;
            else if(f>s) cout<<2<<endl;
            else cout<<3<<endl;
        }
    }
    return 0;
}
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
        int n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        ll g1=0,g2=0;
        for(int i=0;i<n;i+=2){
            g1=__gcd(g1,v[i]);
        }
        for(int i=1;i<n;i+=2){
            g2=__gcd(g2,v[i]);
        }
        // cout<<g1<<" "<<g2<<endl;
        ll d=0;
        bool flag=true;
        for(int i=1;i<n;i+=2){
            if(v[i]%g1==0){
                flag=false;
                break;
            }
        }
        if(flag) d=g1;
        else{
            bool ok=true;
            for(int i=0;i<n;i+=2){
                if(v[i]%g2==0){
                    ok=false;
                    break;
                }
            }
            if(ok) d=g2;
        }
        cout<<d<<endl;
    }
    return 0;
}
/*
initially kono ekta set of elements er gcd value ber korte
gele first e value=0 dhore start kora jay.
odd index er gular jonno g1
even index er gular jonno g2
*/
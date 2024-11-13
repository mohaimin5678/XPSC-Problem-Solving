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
        int n,m,h;
        cin>>n>>m>>h;
        priority_queue<int> a,b;
        while(n--){
            int x;
            cin>>x;
            a.push(x);
        }
        while(m--){
            int x;
            cin>>x;
            b.push(x);
        }
        ll ans=0;
        while(!a.empty() && !b.empty()){
            ll x=1LL*h*b.top();
            if(x>a.top()){
                ans+=a.top();
            }
            else ans+=x;
            a.pop();
            b.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}
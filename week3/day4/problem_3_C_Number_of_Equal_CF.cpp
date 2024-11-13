#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int i=0,j=0;
    ll ans=0;
    while(i<n && j<m){
        int cur=a[i], cnt1=0,cnt2=0;
        while(i<n && a[i]==cur){
            cnt1++;
            i++;
        }
        while(j<m && cur>b[j]) j++;
        while(j<m && b[j]==cur){
            cnt2++;
            j++;
        }
        ans+=(1LL*cnt1*cnt2); //1LL for typecasting
    }
    cout<<ans<<endl;
    return 0;
}
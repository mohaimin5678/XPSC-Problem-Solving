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
        vector<int> v(n);
        int zero=0,x=0,one=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]==0) zero++;
            else if(v[i]>=2) x++;
            else if(v[i]==1) one++;
        }
        
        int target=(n+1)/2;
        
        if(zero<=target) cout<<0<<endl;
        else if(x!=0 || zero==n) cout<<1<<endl;
        else if(zero>target && x==0){
            cout<<2<<endl;
        }
        
    }
    return 0;
}
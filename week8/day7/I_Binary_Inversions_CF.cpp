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
        for(int i=0;i<n;i++) cin>>v[i];
        ll ones=0;
        ll mx=0;
        int firstzero=-1;
        int lastone=-1;
        for(int i=0;i<n;i++){
            if(v[i]==0 & firstzero==-1) firstzero=i;
            if(v[i]==1) lastone=i;

            if(v[i]==1) ones++;
            else mx+=ones;
        }
        
        vector<int> type1=v;
        vector<int> type2=v;
        type1[firstzero]=1;
        ll ans=0;
        ones=0;
        for(int i=0;i<n;i++){
            if(type1[i]==1) ones++;
            else ans+=ones;
        }
        mx=max(ans,mx);
        type2[lastone]=0;
        ans=0;
        ones=0;
        for(int i=0;i<n;i++){
            if(type2[i]==1) ones++;
            else ans+=ones;
        }
        mx=max(ans,mx);
        cout<<mx<<endl;
    }
    return 0;
}
/*
inversion means how many larger values are in 
a[0] to a[i-1] for a[i]. 
testcase: 
8
1 0 1 1 0 0 0 1

initial inversion: 1 0 1 1 0 0 0 1
                     1     3 3 3   =10

lets change the first 0 to 1.
new array:  1 1 1 1 0 0 0 1
                    4 4 4     =12

new array:  1 0 1 1 0 0 0 0
              1     3 3 3 3   =13

so max of (10,12,13) is the answer. 
*/
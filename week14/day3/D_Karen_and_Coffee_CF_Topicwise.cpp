#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> dif(200002,0);
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        dif[l]++;
        dif[r+1]--;
    }
    vector<int> ans(200002,0);
    for(int i=1;i<=200000;i++){
        dif[i]=dif[i-1]+dif[i];
        ans[i]=ans[i-1]+(dif[i]>=k);
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        // cout<<ans[a]<<" "<<ans[b]<<ln;
        cout<<ans[b]-ans[a-1]<<ln;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mohaimin();
}
/*




90 91 92 93 94 95 96 97 98 99 100
0  1  1  0  0  -1 0  1  -1 0   -1
------------------------------------
0  1  2  2  2  1  1  2  1  1   0       prefix of dif

90 91 92 93 94 95 96 97 98 99 100
--------------------------------------
0  0  1  2  3  3  3  4  4  4   4        ans vector  

*/
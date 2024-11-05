#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        map<int,set<int>> mp;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            mp[x].insert(i);
        }
        // for(auto [x,y]:mp){
        //     cout<<x<<" -> ";
        //     for(auto val:y){
        //         cout<<val<<" ";
        //     }
        //     cout<<endl;
        // }
        while(m--){
            int l,r;
            cin>>l>>r;
            if((mp.find(l)==mp.end()) || (mp.find(r)==mp.end())){
                cout<<"NO"<<endl;
            }
            else{
                int starting,ending;
                starting=*mp[l].begin();
                ending=*mp[r].rbegin();
                if(starting<ending) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}

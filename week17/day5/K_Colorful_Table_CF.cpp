#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    vector<vector<int>> pos(k);
    set<int> st;

    for(int i=0;i<n;i++){
        pos[v[i]-1].push_back(i);   //0-base indexing
        st.insert(i);
    }

    vector<int> ans(k);
    for(int x=0;x<k;x++){
        if(!pos[x].size()) continue;

        ans[x]= 2*(*st.rbegin()-*st.begin()+1);
        for(auto p:pos[x]){
            st.erase(p);
        }
    }
    for(int x:ans) cout<<x<<" ";
    cout<<ln;
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
/*

*/

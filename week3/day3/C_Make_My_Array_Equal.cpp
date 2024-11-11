#include<bits/stdc++.h>
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
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int x=0;
        set<int> unique;
        for(int i=0;i<n;i++){
            if(v[i]!=x) unique.insert(v[i]);
        }

        if(unique.size()==0 || unique.size()==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
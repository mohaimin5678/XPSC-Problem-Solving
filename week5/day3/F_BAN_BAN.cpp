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
        int m=3*n;
        
        vector<pair<int,int>> v;
        int i=1,j=m;
        while(i<j){
            v.push_back({i,j});
            i+=3;
            j-=3;
        }
        cout<<v.size()<<endl;
        for(auto [x,y]:v){
            cout<<x<<" "<<y<<endl;
        }
        
    }
    return 0;
}
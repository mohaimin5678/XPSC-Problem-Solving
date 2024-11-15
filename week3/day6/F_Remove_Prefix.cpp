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
        set<int> s;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s.count(v[i])) break;
            s.insert(v[i]);
            cnt++;
        }
        cout<<n-cnt<<endl;
    }
    return 0;
}
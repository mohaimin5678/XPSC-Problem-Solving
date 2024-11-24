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
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]]++;
    }
    char c='a';
    string s;
    for(int i=n-1;i>=0;i--){
        if(mp[v[i]]>0){
            s.push_back(c+mp[v[i]]-1);
            mp[v[i]]--;
        }
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    }
    return 0;
}
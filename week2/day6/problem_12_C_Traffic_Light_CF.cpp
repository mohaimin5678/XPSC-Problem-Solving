#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
void mohaimin(){
    int n;
    char c;
    string s;
    cin>>n>>c>>s;
    s=s+s;
    // cout<<s<<endl;
    if(c=='g'){
        cout<<0<<endl;
        return;
    }
    // priority_queue<int> green;
    int lim;
    for(int i=n;i<s.size();i++){
        if(s[i]=='g'){
            lim=i;
            break;
        }
    }
    // int last=green.top();
    vector<int> point;
    vector<int> grn;
    for(int i=0;i<n;i++){
        if(s[i]==c) point.push_back(i);
    }
    for(int i=0;i<=lim;i++){
        if(s[i]=='g') grn.push_back(i);
    }
    int ans=INT_MIN;
    sort(point.begin(),point.end());
    sort(grn.begin(),grn.end());
    for(int i=0;i<point.size();i++){
        auto it=upper_bound(grn.begin(),grn.end(),point[i]);
        int val=*it;
        ans=max((val-point[i]),ans);
    }
    cout<<ans<<endl;
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
    return 0;
}
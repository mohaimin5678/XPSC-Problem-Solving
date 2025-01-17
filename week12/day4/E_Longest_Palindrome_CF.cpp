#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;

void mohaimin(){
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<bool> vis(101,false);
    vector<string> front,back;
    for(int i=0;i<n-1;i++){
        string s=v[i];
        reverse(s.begin(),s.end());
        for(int j=i+1;j<n;j++){
            if(s==v[j] && !vis[j]){
                vis[i]=true;
                vis[j]=true;
                front.push_back(v[i]);
                back.push_back(v[j]);
                break;
            }
        }
    }
    vector<string> mid;
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            string s=v[i];
            reverse(s.begin(),s.end());
            if(s==v[i]){
                mid.push_back(v[i]);
                break;
            }
        }
    }
    int totalsize=(front.size()*m)+(mid.size()*m)+(back.size()*m);
    if(totalsize==0){
        cout<<totalsize<<endl;
        return;
    }
    cout<<totalsize<<endl;
    for(auto x:front) cout<<x;
    // cout<<endl;
    for(auto x:mid) cout<<x;
    // cout<<endl;
    reverse(back.begin(),back.end());
    for(auto x:back) cout<<x;
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    mohaimin();
    
}

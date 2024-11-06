#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
void solution(){
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> copy;
    for(int i=0;i<n;i++){
        cin>>v[i];
        copy.push_back(v[i]);
    }
    string s;
    cin>>s;
    bool flag=false;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0') flag=true;
        if(s[i]=='1') cnt++;
    }
    if(!flag){
        for(int x:v){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    if(cnt==0){
        for(int x:v){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    map<int,int> one,zero;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            one[v[i]]=i;
        }
        else{
            zero[v[i]]=i;
        }
    }
    map<int,int> change;
    sort(copy.begin(),copy.end());
    int idx=n-1;
    for(auto it=one.rbegin();it!=one.rend();it++){
        int x=it->first;
        int y=it->second;
        change[y]=copy[idx];
        idx--;
    }
    // cout<<idx<<endl; //4
    idx=0;
    for(auto it=zero.begin();it!=zero.end();it++){
        int x=it->first;
        int y=it->second;
        change[y]=copy[idx];
        idx++;
    }
    vector<int> ans(n,-1);
    for(auto [x,y]:change){
        // cout<<x<<" "<<y<<endl;
        ans[x]=y;
    }
    // sort(copy.begin(),copy.end());
    // idx=0;
    // for(int i=0;i<n;i++){
    //     if(ans[i]==-1){
    //         ans[i]=copy[idx];
    //         idx++;
    //     }
    // }
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solution();
    }
    return 0;
}
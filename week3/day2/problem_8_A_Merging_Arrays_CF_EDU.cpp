#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<int> ans;
    int i=0,j=0;
    while(i<n || j<m){
        if(i==n && j<m){
            ans.push_back(b[j]);
            j++;
        }
        else if(i<n && j==m){
            ans.push_back(a[i]);
            i++;
        }
        else if(a[i]<b[j]){
            ans.push_back(a[i]);
            i++;
        }
        else{
            ans.push_back(b[j]);
            j++;
        }
    }
    for(int v:ans){
        cout<<v<<" ";
    }
    cout<<'\n';
    return 0;
}
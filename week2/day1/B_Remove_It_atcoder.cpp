#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    cin>>n>>x;
    int a[n];
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=x) v.push_back(a[i]);
    }
    for(int val:v){
        cout<<val<<" ";
    }
    return 0;
}
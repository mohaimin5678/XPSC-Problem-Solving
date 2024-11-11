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
    int i=0,j=0,cnt=0;
    while(j<m){
        if(i<n && a[i]<b[j]){
            cnt++;
            i++;
        }
        else{
            cout<<cnt<<" ";
            j++;
        }
    }
    return 0;
}
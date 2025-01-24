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
    string a,b;
    cin>>a>>b;
    int i=0,j=0,cnt=0;
    while(i<n && j<m){
        if(a[i]==b[j]){
            cnt++;
            i++;
            j++;
        }
        else j++;
    }
    cout<<cnt<<ln;
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
}
#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,lim;
    cin>>n>>lim;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int total=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]>=lim){
            total+=a[i];
        }
        else if(a[i]==0){
            if(total>0){
                total--;
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
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
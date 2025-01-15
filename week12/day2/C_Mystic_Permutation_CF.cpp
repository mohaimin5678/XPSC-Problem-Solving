#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b=a;
    sort(b.begin(),b.end());
    // for(int x:b) cout<<x<<" ";
    // cout<<endl;
    bool minus=false;
    if(n==1){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            if(i==n-1){
                int j=i-1;
                if(a[j]!=b[i]) swap(b[i],b[j]);
                else minus=true;
                
            }
            else{
                int j=i+1;
                if(a[j]!=b[i]) swap(b[i],b[j]);
                else minus=true;
            }
        }
        if(minus) break;
    }
    if(minus) cout<<-1<<endl;
    else{
        for(int x:b){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) mohaimin();
    return 0;
}
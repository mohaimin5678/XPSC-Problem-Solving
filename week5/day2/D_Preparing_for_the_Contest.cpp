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
        int n,k;
        cin>>n>>k;
        if(k==0){
            for(int i=n;i>0;i--){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else if(k==n-1){
            for(int i=1;i<=n;i++){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<1<<" ";
            int big=n-k+1;
            for(int i=big;i<=n;i++){
                cout<<i<<" ";
                
            }
            priority_queue<int> pq;
            for(int i=2;i<big;i++){
                pq.push(i);
            }
            while(!pq.empty()){
                cout<<pq.top()<<" ";
                pq.pop();
            }
            cout<<endl;
        }
    }
    return 0;
}
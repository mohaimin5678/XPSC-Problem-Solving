#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        priority_queue<int> pq;
        for(int i=1;i<=n;i++){
            pq.push(i);
        }
        vector<pair<int,int>> v;
        while(pq.size()!=1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            int sum=(x+y);
            int z;
            if(sum%2==0) z=(sum/2);
            else z=(sum/2)+1;
            v.push_back({x,y});
            pq.push(z);
        }
        cout<<pq.top()<<endl;
        for(auto [x,y]:v){
            cout<<x<<" "<<y<<endl;
        }
    }
    return 0;
}
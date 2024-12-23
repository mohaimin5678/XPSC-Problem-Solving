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
        int n;
        cin>>n;
        deque<int> d(n);
        for(int i=0;i<n;i++) cin>>d[i];
        sort(d.begin(),d.end());
        for(int i=1;i<n;i++){
            if(i%2==1){
                d.pop_front();
            }
            else d.pop_back();
        }
        cout<<d.front()<<endl;
    }
    return 0;
}
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
        vector<int> v(n);
        
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int pos=0;
        while(pos<n && v[pos]==0) pos++;
        ll sum=0;
        for(int i=pos;i<n-1;i++){
            sum+=v[i];
            if(v[i]==0) sum++;
            
        }

        cout<<sum<<endl;
    }
    return 0;
}
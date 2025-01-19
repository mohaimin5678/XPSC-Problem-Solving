#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;

void mohaimin(){
    int n;
    cin >> n;
    vector<int> freq(n+1,0);
    for (int i=0;i<n;i++) {
        int x;
        cin>>x;
        if(x<=n) {
            freq[x]++;
        }
    }
    vector<int> position(n+1,0);
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j+=i) {
            position[j]+= freq[i];
        }
    }
    int ans= *max_element(position.begin(), position.end());
    cout<<ans<<ln;
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
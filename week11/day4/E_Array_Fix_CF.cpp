#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> ans;
    ans.push_back(v[n-1]);
    for(int i=n-2;i>=0;i--){
        if(v[i]>ans.back()){
            int ldigit=v[i]%10;
            int fdigit=v[i]/10;
            ans.push_back(ldigit);
            ans.push_back(fdigit);
        }
        else ans.push_back(v[i]);
    }
    // sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size()-1;i++){
        if(ans[i]>ans[i+1]){
            cout<<"NO"<<ln;
            return;
        }
    }
    cout<<"YES"<<ln;
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
    return 0;
}
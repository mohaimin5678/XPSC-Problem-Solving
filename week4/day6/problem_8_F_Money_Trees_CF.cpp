#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
bool divisible(int x, int y) {
    return x % y == 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n),h(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        for(int i=0;i<n;i++){
            cin>>h[i];
        }
        if(n==1){
            if(k<v[0]) cout<<0<<endl;
            else cout<<1<<endl;
        }
        else{
            int l=0,r=0;
            int ans=0;
            int sum=0;
            while(r<n){
                sum+=v[r];
                if (r == 0 || divisible(h[r - 1], h[r])) {
                    while (sum > k) {
                        sum -= v[l];
                        l++;
                    }
                    ans = max(ans, r - l + 1);
                } else {
                    l = r;
                    sum = v[r];
                    if(sum<=k){
                        ans=max(ans,(r-l+1));
                    }
                }
                r++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
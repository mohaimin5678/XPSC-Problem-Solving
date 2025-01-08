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
        for (int i = 0;i < n;i++) cin >> v[i];

        sort(v.begin(),v.end());

        auto check = [&](int time) {
            int cnt = 1, l = 0;
            for (int r = 0;r < n;r++){
                if ((v[r] - v[l]) > 2 * time){
                    l = r;
                    cnt++;
                }
            }
            return cnt <= 3;
        };

        int l=0, r=1e9,mid,ans;
        while(l<=r) {
            mid=l+(r-l)/2;
            if (check(mid)) {
                ans=mid;
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n;i++) {
            cin >> v[i];
        }
        map<int, int> cnt;
        for (int i = 0;i < n;i++) {
            for (int j = 2;j * j <= v[i];j++) {
                if (v[i] % j == 0) {
                    while (v[i] % j == 0) {
                        cnt[j]++;
                        v[i] /= j;
                    }
                }
            }
            if (v[i] > 1) {
                cnt[v[i]]++;
            }
        }
        bool ok = true;
        for (auto [x, y] : cnt) {
            if (y % n != 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
/*
they will give us an array where we can do: 
-> choose Ai & Aj and a divisor of Ai which is x
-> then replace Ai with (Ai/x) & Aj with (Aj*x). 
by doing these operation we have to make all elements
of the array equal. 

*/
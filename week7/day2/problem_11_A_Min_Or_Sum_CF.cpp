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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        int sum=v[1]|v[2];
        for(int i=3;i<=n;i++){
            sum=(sum|v[i]);
        }
        cout<<sum<<endl;
    }
    return 0;
}
/*
All we can do is to serially make the OR operation. 
This will minimize the original sum. 
because A1|A2|A3|...|An < A1+A2+A3+...+An
*/
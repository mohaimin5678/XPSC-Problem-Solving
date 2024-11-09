//https://codeforces.com/contest/1843
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int sum=0;
        int a[n];
        vector<int> v;
        int cnt=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=abs(a[i]);
            if(a[i]) v.push_back(a[i]);

            if(a[i]<0) cnt++;
        }
        for(int i=1;i<v.size();i++){
            if(v[i]<0 && v[i-1]<0){
                cnt--;
            }
        }
        cout<<sum<<" "<<cnt<<endl;
    }
    return 0;
}
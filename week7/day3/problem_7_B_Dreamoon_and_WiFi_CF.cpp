#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a,b;
    cin>>a>>b;
    int sumA=0,sumB=0,cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='+') sumA++;
        else sumA--;

        if(b[i]=='+') sumB++;
        else if(b[i]=='?') cnt++;
        else sumB--;
    }
    int n=(1<<cnt);
    int rem=sumA-sumB;
    float ans=0;
    int SetBit=__lg(n)-1;
    for(int i=0;i<n;i++){
        int s=0;
        for(int k=SetBit;k>=0;k--){
            if((i>>k)&1) s++;
            else s--;
        }
        // cout<<s<<" ";
        if(s==rem) ans++;
    }
    ans/=(1.00*n);
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}
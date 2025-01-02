#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n),pre(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i==0) pre[i]=v[i];
        else pre[i]=pre[i-1]+v[i];
    }
    int q;
    cin>>q;
    while(q--){
        int k;
        cin>>k;
        int l=0,r=n-1,mid,ans;
        while(l<=r){
            mid=(l+r)/2;
            if(pre[mid]>=k){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans+1<<endl;
    }
    return 0;
}
/*
binary search closest to the right is used here. Because we need
to find the pile number & since its int a serial, so the possibility
of availability on the left area exists. so thats why closest to
the right is the best way. 
*/
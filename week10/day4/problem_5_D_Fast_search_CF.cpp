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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int q;
    cin>>q;
    while(q--){
        int key1,key2;
        cin>>key1>>key2;
        //left
        int l1=0,r1=n-1,mid1,ans1=n;
        while(l1<=r1){
            mid1=(l1+r1)/2;
            if(v[mid1]>=key1){
                ans1=mid1;
                r1=mid1-1;
            }
            else l1=mid1+1;
        }
        //right
        int l2=0,r2=n-1,mid2,ans2=-1;
        while(l2<=r2){
            mid2=(l2+r2)/2;
            if(v[mid2]<=key2){
                ans2=mid2;
                l2=mid2+1;
            }
            else r2=mid2-1;
        }
        // cout<<ans1<<" "<<ans2<<endl;
        if((ans1>ans2) || (ans1==n || ans2==-1)) cout<<0<<" ";
        else cout<<ans2-ans1+1<<" ";
    }
    return 0;
}
/*
here we need to use closest to the right for key1
and closest to the left for key2
but if somehow ans1>ans2 then there will be no valid range so 0
also if ans1 stuck into n OR ans2 stays on -1 that means one or
maybe both of them didn't get any index position. for key1, maybe
there was no value greater than it so it stays on -1. And for key2,
maybe there was no value smaller than it so it stays on n. if any
of that happens, there is no legit range so answer is again 0.
ELSE just calculating the range and print it. 
*/
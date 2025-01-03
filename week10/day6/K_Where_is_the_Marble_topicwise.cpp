#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    int t=1;
    while(cin>>n>>q && n!=0 && q!=0){
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        cout<<"CASE# "<<t<<":"<<endl;
        while(q--){
            int key;
            cin>>key;
            int l=0,r=n-1,ans=-1,mid;
            while(l<=r){
                mid=(l+r)/2;
                if(v[mid]==key){
                    ans=mid;
                    r=mid-1;
                }
                else if(v[mid]>key){
                    r=mid-1;
                }
                else l=mid+1;
            }
            
            if(ans==-1){
                cout<<key<<" not found"<<endl;
            }
            else cout<<key<<" found at "<<ans+1<<endl;
        }
        t++;
    }
    return 0;
}
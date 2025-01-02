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
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int m;
    cin>>m;
    vector<int> q(m);
    for(int i=0;i<m;i++){
        cin>>q[i];
    }
    for(int i=0;i<m;i++){
        int key=q[i];
        
        //left
        int l=0,r=n-1,mid,ans1=-1;
        while(l<=r){
            mid=(l+r)/2;
            if(v[mid]<key){
                ans1=v[mid];
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        }

        //right
        int f=0,lst=n-1,middle,ans2=n;
        while(f<=lst){
            middle=(f+lst)/2;
            if(v[middle]>key){
                ans2=v[middle];
                lst=middle-1;
            }
            else {
                f=middle+1;
            }
        }
        if(ans1==-1) cout<<"X"<<" ";
        else cout<<ans1<<" ";

        if(ans2==n)  cout<<"X"<<endl;
        else cout<<ans2<<endl;
    }
    return 0;
}
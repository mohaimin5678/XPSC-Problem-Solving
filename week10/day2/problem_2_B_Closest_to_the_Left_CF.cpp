#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(n),q(k);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<k;i++) cin>>q[i];
    for(int i=0;i<k;i++){
        int key=q[i];
        
        int l=0,r=n-1,mid,ans=-1;
        while(l<=r){
            mid=(l+r)/2;
            if(v[mid]<=key){
                ans=mid;
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        }
        cout<<ans+1<<endl;    
    }
    return 0;
}
/*
they want us to print the maximum index which is <=k
example: 
5 5
3 3 5 8 9
2 4 8 1 10
for key=2, no such index so ans=0
for key=4, 1st & 2nd index so ans=2
for key=8, 1st to 4th index so ans=4
for key=1, no such index so ans=0
for key=210, all index are <key so answer is the maximum index 5. 

we'll use the binary search here. 
logic:
if--> jodi v[mid] ta key theke <= hoy tahole sheta already answer e 
contribute kortese so ans=mid kore amra next possible answer search
korbo. 
else--> jodi v[mid]>key hoy tahole r=mid-1 kore shei range e amra 
possible answer search korbo. 

loop breaking condition: l>r hole break;
*/
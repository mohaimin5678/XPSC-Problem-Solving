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
        
        int l=0,r=n-1,mid,ans=n;
        while(l<=r){
            mid=(l+r)/2;
            if(v[mid]>=key){
                ans=mid;
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        cout<<ans+1<<endl;    
    }
    return 0;
}
/*
they want us to print the maximum index which is >=k
example: 
5 5
3 3 5 8 9
2 4 8 1 10
for key=2, all index are >key so answer is the minimum index 1.
for key=4, 3rd to 5th index so answer is 3
for key=8, 4th & 5th index so answe is 4
for key=1, all index are >key so answer is the minimum index 1.
for key=10, none are true so answer is 5+1=6

logic: 
if-> jodi mid ta key er >= hoy tahole sheta already answer e contribute
kortese so shetake answer e set kore amra next possible answer search
korbo. Tai amra r=mid-1 kore er niche kono possible answer pai kina
check korbo. 
else-> jodi mid already <key hoy tahole l=mid+1 kore oi range theke
possible answer khujbo. 
*/
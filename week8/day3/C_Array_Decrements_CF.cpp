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
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        vector<int> v(n);
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            v[i]=a[i]-b[i];
            mx=max(mx,v[i]);
        }
        if(n==1){
            if(a[0]<b[0]) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else{
            bool flag=true;
            for(int i=0;i<n;i++){
                if(a[i]<b[i]){
                    flag=false;
                    break;
                }
                if(v[i]<mx && b[i]!=0){
                    flag=false;
                    break;
                }
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;  
        }
    }
    return 0;
}
/*
summation vector will take all a[i]-b[i] & let mx holding the max 
difference. 
since any a[i]-b[i]=v[i] can never go above mx's value so lets 
check if there are any value of v[i] is less than mx, that means
they will reach b[i] faster than others & if that happen then NO. 
but b[i] also can't be 0, because according to the statement, we
can't decrease after 0. so v[i]<mx can be acceptable for that 
particular case. So for that we'll simply check if any v[i]<mx && 
b[i]!=0 then false. it will handle all cases including b[i]=0
again if a[i]<b[i] then its already false. & for that we have to
give another separate condition. why?
because for a case like this: 
3
2 2 2
5 5 5
the mx=-3 & for this if v[i]<mx && b[i]!=0 the flag won't be false!
so a a[i]<b[i] condition is also needed before that condition. 
*/
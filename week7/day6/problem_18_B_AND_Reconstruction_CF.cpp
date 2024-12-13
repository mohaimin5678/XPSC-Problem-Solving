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
        vector<int> v(n-1);
        for(int i=0;i<n-1;i++){
            cin>>v[i];
        }
        vector<int> ans(n);
        for(int i=1;i<n-1;i++){
            ans[i]=(v[i-1]|v[i]);
        }
        if(n>2){
            ans[0]=v[0];    //first
            ans[n-1]=v[n-2];    //last
        }
        if(n==2){
            //since ans[0]&ans[1] should be v[0], we know that 
            //v[0]&v[0] is also v[0]
            cout<<v[0]<<" "<<v[0]<<endl;
            continue;
        }
        bool flag=true;
        for(int i=0;i<n-1;i++){
            if((ans[i]&ans[i+1])!=v[i]) flag=false;
        }
        if(flag){
            for(int x:ans){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}
/*
5
3 5 4 2
we need to create the answer
we know that if we want A&B=5=v[1], we need to find 2 value where 
in both A and B, all the on bits of 5 are exists! Since we have 
to make it using the V array. lets put 3|5=7 on ans[1]. 
again to find 4==v[2], lets put 5|4=5 on ans[2].
again to find 2==v[3], lets put 4|2=6 on ans[3].
now ans=[ _ 7 5 6 _ ]
lets put ans[0]=v[0] & ans[4]=v[3], why?
because 3&7==3==v[0] also 6&2==2==v[3]
now ans=[ 3 7 5 6 2 ]
now lets check if we can make v from ans. or else we'll show -1
v[0]=3 ---> ans[0]&ans[1]=3&7=3 
v[1]=5 ---> ans[1]&ans[2]=7&5=5 
v[2]=4 ---> ans[2]&ans[3]=5&6=4 
v[3]=2 ---> ans[3]&ans[4]=6&2=2
so all are ok. 
*/
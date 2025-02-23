#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(k==2 || k==3 || k==5){
        for(int i=0;i<n;i++){
            if(v[i]%k==0){
                cout<<0<<ln;
                return;
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            int top=ceil((v[i]*1.0)/k);
            mn=min(mn,(top*k)-v[i]);
        }
        cout<<mn<<ln;
    }
    else{
        for(int i=0;i<n;i++){
            if(v[i]%k==0){
                cout<<0<<ln;
                return;
            }
        }
        int mn1=INT_MAX;
        int even=0;
        for(int i=0;i<n;i++){
            if(v[i]%2==0) even++;
            int top=ceil((v[i]*1.0)/k);
            mn1=min(mn1,(top*k)-v[i]);
        }
        int mn2=max(0,2-even);
        cout<<min(mn1,mn2)<<ln;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        mohaimin();
    }
}
/*
if individually any element is divisible by k then answer is 0
else check which individual element comes closest to a value 
which will be divisible by k. 
for k=4, there will be an extra check which is if there is atleast
two even number exists, then those two even's sum will obviously
divisible by k. So if vector has two/more even number already 
then the answer will be 0. Otherwise we need to make atleast two
odd numbers even. if we have 1 even already then we'll need another
even number so answer=1, if we have 0 even then we'll need two
even number so answer=2. 
so to put directly on an equation we'll simply do max(0,2-cnt)
here cnt is the count of even numbers. 
*/
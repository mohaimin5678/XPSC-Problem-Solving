#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    if(v[0]!=v[1]){
        cyes;
        return;
    }
    else if(v[0]==v[1] && v[0]==1){
        cno;
        return;
    }
    else{
        for(int i=1;i<n;i++){
            if(v[i]%v[0]!=0){
                cyes;
                return;
            }
        }
        cno;
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
if first 2 after sort aren't same then straight YES.
if first 2 after sort are same & both are 1 then straight NO. 
if first 2 after sort are same but not 1 then check if any other
element divisible by first element is !=0. if we find one, just 
put it into the first position & we can make an array which's final
mod value is !=0. 
how? 
6
5 2 10 10 10 2
after sort: 2 2 5 10 10 10
here first 2 are same. so x=2
checking from the 2nd element:- 
2%x==0 
5%2==1 so we found our target 
now what we should do is that we'll put it up front. 
5 2 2 10 10 10
so 5%2==1%2==1%10==1%10==1%10==1 which is !=0 so this is how
we can rearrange the array. 

also we can solve this using gcd. 
count all elements & check if the final gcd occurs more than 1 or
not. if it occurs then NO, else yes. 
*/
#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    string a,b;
    cin>>a>>b;
    if(a==b){
        cyes;
        cout<<a<<ln;
        return;
    }
    char x,y;
    bool flag=false;
    for(int i=0;i<a.size()-1;i++){
        for(int j=0;j<b.size()-1;j++){
            if(a[i]==b[j] && a[i+1]==b[j+1]){
                x=a[i];
                y=a[i+1];
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    if(flag){
        cyes;
        cout<<"*"<<x<<y<<"*"<<ln;
    }
    else{
        if(a[0]==b[0]){
            cyes;
            cout<<a[0]<<"*"<<ln;
        }
        else if(a[a.size()-1]==b[b.size()-1]){
            cyes;
            cout<<"*"<<a[a.size()-1]<<ln;
        }
        else cno;
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
checking only 2 size substring is enough. 
so we took 2 char & a bool for flag. if serial wise 2 char from
a & b matches then we'll put them into two char variable & make
flag true. 
if flag is true then answer exists. cause asterisks number can be
atmost 2 & we already have 2. So it will always fill up the conditions. 
but if flag is not true then there will be atmost 1 character that
can be matched & it can't be in the middle because then we'll have
to put two * on both side of the matched character & then it'll
become asterisks number>matched character's number which is NO. 
so if a[0]==b[0] then yes with the answer a[0]*
& a[last]==b[last] then yes with the answer *a[last]

*/
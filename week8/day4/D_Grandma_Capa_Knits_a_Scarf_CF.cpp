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
        string s;
        cin>>n>>s;
        int ans=INT_MAX;
        for(char c='a';c<='z';c++){
            int i=0,j=n-1;
            int cnt=0;
            while(i<j){
                if(s[i]==s[j]){
                    i++;
                    j--;
                    continue;
                }
                if(s[i]!=s[j]){
                    if(s[i]==c){
                        i++;
                        cnt++;
                    }
                    else if(s[j]==c){
                        j--;
                        cnt++;
                    }
                    else{
                        cnt=INT_MAX;
                        break;
                    }
                }
                
            }
            ans=min(cnt,ans);
        }
        if(ans==INT_MAX) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
/*
testcase: 
8
rprarlap

serially for loop lets take 'c' as a,l,p,r 
for c='a',
s[i]!=s[j] & s[i]!='a' also s[j]!='a' so cnt=INT_MAX for a & break

for c='l',
s[i]!=s[j] & s[i]!='l' also s[j]!='l' so cnt=INT_MAX for l & break

for c='p',
s[i]!=s[j] & s[j]=='p' so cnt=1, j--;
again s[i]!=s[j] & s[i]!='p' also s[j]!='p' so cnt=INT_MAX for p & break

for c='r',
s[i]!=s[j] (r!=p) & s[i]=='r' so cnt=1, i++;   
s[i]==s[j] (p==p) i++,j-- & continue;
s[i]!=s[j] (r!=a) & s[i]=='r' so cnt=2, i++;
s[i]==s[j] (a==a) i++,j-- & continue;
s[i]!=s[j] (r!=l) & s[i]=='r' so cnt=3, i++;
while condition break;
ans=3;
*/
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
        int n,k;
        cin>>n>>k;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(i%k!=v[i]%k) cnt++;
        }
        if(cnt==0) cout<<0<<endl;
        else if(cnt==2) cout<<1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
/*
the best way to solve this is to take i as index & j as index's value
then we'll mod it by k, then we'll check if both's mod result is not
same then we'll count. if count==0 then 0, if count==2 then 1, if more
than 2 then -1. 
explanation: 
testcase 2: 
4 2
3 4 1 2 

1 2 3 4 -->idx
now for i=1, 1%2==1==3%2
for 2, 2%2==0==4%2
for 3, 3%2==1==1%2
for 4, 4%2==0==2%2
so cnt=0 & answer is also 0

testcase 3: 
4 2
3 1 4 2

1 2 3 4 -->idx
for i=1, 1%2==1==3%2
for i=2, 2%2==0 but 1%2==1 so cnt=1
for i=3, 3%2==1 but 4%2==0 so cnt=1+1=2
for i=4, 4%2==0==2%2
now cnt=2 so answer is 1
why?
because where we found the mismatch we can simply swap them & then
the array will be, 
3 4 1 2
here 3-1==2==k so swap them
1 4 3 2
then 4-2==2==k so swap them
1 2 3 4
sorting done!
*/
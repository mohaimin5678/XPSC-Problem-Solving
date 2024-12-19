#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    if(v[n-1]==1) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            if(v[i]==0){
                if(i==0 || v[i-1]==0){ //first index/previous index 0
                    ans.push_back(0);
                }
                else{
                    if(v[i-1]==1){
                        int j=i-1;
                        int cnt=0;
                        int nxt;
                        while(j>=0 && v[j]==1){
                            cnt++;
                            j--;
                        }
                        nxt=j;
                        int tmp=cnt;
                        while(cnt--) ans.push_back(0);
                        ans.push_back(tmp);
                        i=nxt+1; 
                        //because it will get decrement for loop condition
                    }
                }
            }
            
        }
        for(int x:ans) cout<<x<<" ";
        cout<<endl;
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
    return 0;
}
/*
NO when last index is 1. 
Here we need to make a vector from V. 
initially our making vector is empty. 
traversing from the v[n-1] we'll check how many consecutive 1s are
exists before a particular 0. We'll push 0 for those consecutive 1s
& for that particular 0, we'll push the "number of ones" amount. 
lets see with a testcase:
6
1 0 0 1 1 0
ans=[]
here v[5]=0 so lets check how many consecutive 1s are before it. 
v[4] & v[3] so cnt=2,
since there is two 1s, so for each we'll push 0. ans=[0 0 ]
And for that particular 0, we'll push cnt. ans=[0 0 2 ]

then v[2]=0 & v[1]!=1 so push 0 for v[2]. ans=[0 0 2 0]

then v[1]=0 & v[0]=1 so there is only one 1s before v[1]. 
so we'll push 0 for that 1. ans=[0 0 2 0 0 ]
And for that particular 0, we'll push cnt which is 1. 
so final ans=[0 0 2 0 0 1]
*/
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=31;i>=0;i--){
        if((n>>i)&1) v.push_back(1);
        else v.push_back(0);
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<32;i++){
        if(v[i]==1){
            if((i+1)<32 && v[i+1]==1){
                v[i]=-1;
                int j=i+1;
                while(j<=32){
                    if(v[j]!=1) break;
                    v[j]=0;
                    j++;
                }
                v[j]=1;
                i=j-1;
            }
        }
    }
    cout<<32<<endl;
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
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
testcase: n=27
binary = 0000011011

reverse= 1101100000
loop:    i
v[i]==1 & v[i+1]==1 so v[i]=-1; j=i+1

reverse= -1 101100000
loop:     i j
v[j]==1 so v[j]=0 & j++;

reverse= -1 001100000
loop:     i  j
while loop break cause v[j]!=1
so v[j]=1; & i=j-1;

reverse= -1 011100000
loop:       ij
v[i]!=1 so continue;

reverse= -1 011100000
loop:        i
v[i]==1 & v[i+1]==1 so v[i]=-1; j=i+1

reverse= -1 0 -11100000
loop:          ij
v[j]==1 so v[j]=0 & j++;

reverse= -1 0 -10100000
loop:          i j
v[j]==1 so v[j]=0 & j++;

reverse= -1 0 -10000000
loop:          i  j
while loop break cause v[j]!=1
so v[j]=1; & i=j-1;

reverse= -1 0 -10010000
loop:            ij
v[i]!=1 so continue;

reverse= -1 0 -10010000
loop:             i
v[i]==1 but v[i+1]!=1 so continue;

reverse= -1 0 -10010000
loop:              i
v[i]!=1 so continue;

then till the end it won't insert into if conditions. 
*/
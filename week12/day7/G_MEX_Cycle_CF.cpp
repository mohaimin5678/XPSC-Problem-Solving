#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,x,y;
    cin>>n>>x>>y;
    x--;
    y--;
    vector<int> v(n);
    int j=0;
    for(int i=x;i<n;i++){
        v[i]=j;
        j++;
        if(j==2) j=0;
    }
    for(int i=0;i<x;i++){
        v[i]=j;
        j++;
        if(j==2) j=0;
    }
    if(n%2==1 || (y-x)%2==0) v[x]=2;
    for(auto val:v) cout<<val<<" ";
    cout<<ln;
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
had to check tutorial to solve this!
condition: if n==odd OR y-x==even then Vx=2
so lets check 4 testcases where
i) n==even & y-x==odd
ii) n==odd & y-x==even
iii) n==even & y-x==even
iV) n==odd & y-x==odd

i) 6 2 5
here n=6==even & 5-2==3==odd
lets x-- & y-- for 0-indexing x=1 & y=4
from 0 to 5-> 0 1 2 3 4 5       
now put 0/1-> 1 0 1 0 1 0       starting from x-index(1 no. index)
for x(1)=[0 2 4] & their mex(1 1 1)=0==x
for y(4)=[1 3 5] & their mex(0 0 0)=1==y
& for all individual their neighbours are for 0->[1,1] & for 1->[0,0]

ii) 5 1 3
here n=5==odd & 3-1=2==even
lets x-- & y-- for 0-indexing x=0 & y=2
from 0 to 4-> 0 1 2 3 4 
now put 0/1-> 0 1 0 1 0     starting from x-index(0th index)
for x(0)=[1 2 4] & their mex(1 0 0)=2 so make v[x]=2
now we got -> 2 1 0 1 0
for y(2)=[0 1 3] & their mex(2 1 1)=0==y
now for v[1]=1==mex(2,0) , v[3]=1==mex(0,0) , v[4]=0==mex(1,2)
all are settled. 

iii) 4 2 4
here n=4==even & 4-2=2==even
lets x-- & y-- for 0-indexing x=1 & y=3
from 0 to 4-> 0 1 2 3 
now put 0/1-> 1 0 1 0       starting from x-index(1 no. index)
for x(1)=[0 2 3] & their mex(1 1 0)=2 so make v[x]=2
now we got -> 1 2 1 0 
for y(3)=[0 1 2] & their mex(1 2 1)=0==y
now for v[0]=1==mex(0,2) , v[2]=1==mex(2,0)
all are settled. 

iv) 7 3 6
here n=7==odd & 6-3=3==odd
lets x-- & y-- for 0-indexing x=2 & y=5
from 0 to 6-> 0 1 2 3 4 5 6 
now put 0/1-> 1 0 0 1 0 1 0     starting from x-index(2 no. index)
for x(2)=[1 3 5] & their mex(0 1 1)=2 so make v[x]=2
now we got -> 1 0 2 1 0 1 0 
for y(5)=[2 4 6] & their mex(2 0 0)=1==y
now for v[0]=1==mex(0,0) , v[1]=0==mex(1,2) , v[3]=1==mex(2,0) ,
        v[4]=0==mex(1,1) , v[6]=0==mex(1,1)
all are settled. 

so if n==odd OR y-x==even then making v[x]=2 is an optimized 
approach.  
*/
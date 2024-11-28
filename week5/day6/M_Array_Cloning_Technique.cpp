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
        map<int,int> frq;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            frq[x]++;
        }
        int mx=0;
        for(auto [x,y]:frq){
            mx=max(mx,y);
        }
        int op=0;
        while(mx<n){
            int add=min(n-mx,mx);
            op+=1+add;
            mx+=add;
        }
        cout<<op<<endl;
    }
    return 0;
}

/*
explanation with testcase:
8 
0 1 3 3 7 0 3 2

here both 3 occurs 3 times. 
so mx=3;
so until we fillup the whole array with the highest occured number
we will keep going. 
1st loop: 
we will create a copy array so op=1. 
we will add min(8-3,3)=3 to operations because we can move 3 amount
of 3 from the copy array to the original array and move any 3 element
from original to copy. so original array will be [3 3 3 3 3 0 3 2]
now mx=3+3=6
2nd loop: 
we will create a copy array so op+=1. so op was 4 & now its 5
we will add min(8-6,6)=2 to operations because we need to move 2
amount of 3 from the copy array to the original array and move
remaining 2 element from original to copy. so original array will
be [3 3 3 3 3 3 3 3]
now mx=6+2=8==n & loop ends. 
*/
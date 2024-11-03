//https://codeforces.com/contest/1793
#include<bits/stdc++.h>
#define shesh '\n'
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
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int mn=1;       //cause permutation starts from 1
        int mx=n;       
        //the highest value of the permutation is the range of array
        
        int l=0,r=n-1;      //two pointers technique
        while(l<r){
            if(a[l]==mn){
                l++;
                mn++;
            }
            else if(a[l]==mx){
                l++;
                mx--;
            }
            else if(a[r]==mn){
                r--;
                mn++;
            }
            else if(a[r]==mx){
                r--;
                mx--;
            }
            else break;
        }
        if(l==r) cout<<-1<<shesh;
        else cout<<l+1<<" "<<r+1<<shesh;
    }
    return 0;
}

/*
logic:
whatever range I select, the highest/lowest value cant be on the
left side or the right side of the range. 
*/
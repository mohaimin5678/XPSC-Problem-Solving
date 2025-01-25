#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int k,n,m;
    cin>>k>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    vector<int> selected;
    int i=0,j=0;
    while(i<n || j<m){
        if(i==n){
            if(b[j]==0){
                k++;
                selected.push_back(0);
            }
            else{
                if(b[j]>k){
                    cout<<-1<<ln;
                    return;
                }
                else selected.push_back(b[j]);
            }
            j++;
        }
        else if(j==m){
            if(a[i]==0){
                k++;
                selected.push_back(0);
            }
            else{
                if(a[i]>k){
                    cout<<-1<<ln;
                    return;
                }
                else selected.push_back(a[i]);
            }
            i++;
        }
        else{
            int x=min(a[i],b[j]);
            if(x==a[i]){
                if(a[i]==0){
                    k++;
                    selected.push_back(0);
                }
                else{
                    if(a[i]>k){
                        cout<<-1<<ln;
                        return;
                    }
                    else selected.push_back(a[i]);
                }
                i++;
            }
            else{
                if(b[j]==0){
                    k++;
                    selected.push_back(0);
                }
                else{
                    if(b[j]>k){
                        cout<<-1<<ln;
                        return;
                    }
                    else selected.push_back(b[j]);
                }
                j++;
            }
        }
    }
    for(int x:selected) cout<<x<<" ";
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
they will provide us K amount of line initially
mono & poly works together & do "line operation"
1) if 0 then K++
2) if any other number then check a[i]/b[i] is <= K 
    -> if it is then do something on that line
    -> else we can't do anything on that line cause it
       doesn't exist. 

so lets check a testcase: 
4 3 2
2 0 5
0 6
here K=4, n=3 & m=2

1) i=0,j=0
here a[i]=2 & b[j]=0 so lets take the minimum so 
b[j]=0 is taken. since its 0 so k=5 now & answer=[0 ]

2) i=0 & j=1
here a[i]=2 & b[j]=6 so lets take a[i]=2, since 2<k(5)
so its taken & answer=[0 2 ]

3) i=1 & j=1
here a[i]=0 & b[j]=6 so lets take a[i]=0 & makes k=6
now & answer=[0 2 0 ]

4) i=2 & j=1
here a[i]=5 & b[j]=6 so lets take a[i]=5, since 5<k(6)
so its taken & answer=[0 2 0 5 ]

5) i=3 & j=1
i==n so only j exists
here b[j]=6 & since 6==k(6) so we can take this. So
final answer is=[0 2 0 5 6]

i=3 & j=2 so while loop break;
*/
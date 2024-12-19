#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    vector<int> v(n);
    deque<int> d;
    for(int i=0;i<n;i++) cin>>v[i];
    string s="";
    int i=0;
    for(i=0;i<n;i++){
        if(d.empty()){
            s.push_back('1');
            d.push_back(v[i]);
        }
        else{
            if(v[i]>=d.back()){
                s.push_back('1');
                d.push_back(v[i]);
                
            }
            else{
                if(v[i]>d.front()){
                    s.push_back('0');
                }
                else{
                    s.push_back('1');
                    d.push_back(v[i]);
                    break;
                }
            }
            
        }
    }
    i++;
    for(;i<n;i++){
        if(v[i]<d.back()){
            s.push_back('0');
        }
        else{
            if(v[i]>d.front()){
                s.push_back('0');
            }
            else{
                s.push_back('1');
                d.push_back(v[i]);
            }
        }
    }
    cout<<s<<endl;
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
start checking the first ascending part. then break when it doesn't
match the condition. 
then proceed the 2nd part of the loop & check if it matches the
conditions. 
then print the s.
*/
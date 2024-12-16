#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s;
    int num=n/3;
    bool evenflag=false;
    bool oddflag=false;
    for(int i=1;i<=num;i++){
        if(i%2==1){
            if(!oddflag){
                for(int j=0;j<3;j++){
                    if(j==2) s.push_back('a');
                    else s.push_back('b');
                }
                oddflag=true;
            }
            else{
                for(int j=0;j<3;j++){
                    if(j==2) s.push_back('b');
                    else s.push_back('a');
                }
                oddflag=false;
            }
            
        }
        else{
            if(!evenflag){
                for(int j=0;j<3;j++){
                    if(j==0) s.push_back('a');
                    else s.push_back('b');
                }
                evenflag=true;
            }
            else{
                for(int j=0;j<3;j++){
                    if(j==0) s.push_back('b');
                    else s.push_back('a');
                }
                evenflag=false;
            }
        }
    }
    if(n-(num*3)!=0){
        int rem=n-(num*3);
        if(num%2==1){
            if(!evenflag){
                for(int j=0;j<rem;j++){
                    if(j==0) s.push_back('a');
                    else s.push_back('b');
                }
                evenflag=true;
            }
            else{
                for(int j=0;j<rem;j++){
                    if(j==0) s.push_back('b');
                    else s.push_back('a');
                }
                evenflag=false;
            }
        }
        else{
            if(!oddflag){
                for(int j=0;j<rem;j++){
                    if(j==2) s.push_back('a');
                    else s.push_back('b');
                }
                oddflag=true;
            }
            else{
                for(int j=0;j<rem;j++){
                    if(j==2) s.push_back('b');
                    else s.push_back('a');
                }
                oddflag=false;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}
/*
[bba abb] [aab baa]
  1   2     3   4

also if num%2==1 means last pattern was odd pattern, so not to make it
palindrome 3, we have to use even pattern if the condition is correct. 
also if num%2==0 means last pattern was even pattern, so after that we
have to use odd pattern. 
evenflag & oddflag is just to use the 3 letter efficiently. If you have
any more shortcut way, feel free to use it. 
*/
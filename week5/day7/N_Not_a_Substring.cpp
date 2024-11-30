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
        string s;
        cin>>s;
        int len=s.size();
        if(s=="()"){
            cout<<"NO"<<endl;
        }
        else{
            bool flag=false;
            for(int i=0;i<len-1;i++){
                if((s[i]=='(' && s[i+1]=='(') || (s[i]==')' && s[i+1]==')')) flag=true;
            }
            string reg;
            if(flag){
                for(int i=0;i<len;i++){
                    reg.push_back('(');
                    reg.push_back(')');
                }
            }
            else{
                for(int i=0;i<len;i++){
                    reg.push_back('(');
                }
                for(int i=0;i<len;i++){
                    reg.push_back(')');
                }
            }
            cout<<"YES"<<endl<<reg<<endl;
        }
    }
    
    return 0;
}
/*
approach explanation: 

))() is S
now target is to build a regular string where S doesn't exist as
a contiguous substring.
now lets take a look at S. we have 2 )) & then a ()
since there is 2 )) , we can simply print ()()()() & there will be
no )) repeated. Since )) is not exist on the making string so S as
a whole also won't be exist on the regular string thus the answer
is correct.  (so if we found same direction twice, we can simply
do this)

)( is S
now target is to build a regular string where S doesn't exist as
a contiguous substring.
now lets take a look at S. But now we have 1 ) & 1 ( 
since there is no repeated duplicate direction, we can simple make
a duplicate regular string! because S is not having it so if the
regular string have it then S won't be a contiguous substring of it. 
so if we make (()) then there is no )( exist. 
*/
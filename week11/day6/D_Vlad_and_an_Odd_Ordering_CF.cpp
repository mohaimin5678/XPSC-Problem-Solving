#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=log2(n)+1;i++){
        int x=(1<<i);
        int start=(x/2);
        int y=(n+start)/x;
        if(k<=y){
            if(k==1){
                cout<<start<<endl;
                return;
            }
            else{
                cout<<start+((k-1)*x)<<endl;
                return;
            }
        }
        else k-=y;
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
kinda most hardest observation problem of the week. 
suppose n=20
first all odds in group 1
second all odds*2<=n in group 2
third all odds*4<=n in group 3 (why not *3? because it'll return odd which are already taken)
forth all odds*8<=n in group 4 (*5, *6 , *7 values are already taken)
fifth all odds*16<=n in group 5 (all before that are already taken)

lets take g=group, x=gap, y=total number on that group, st=start
so:  1 2 3 4 5 6  7  8  9  10  11 12 13 14 15  16 17 18  | 19        |20  -> index 1 based
    [1 3 5 7 9 11 13 15 17 19] [2  6 10 14 18] [4 12 20] | [8]       |[16]
    -------------------------- --------------- --------- | ---       |-----
    g1                          g2             g3        | g4        |g5
    x=2^1=2                     x=2^2=4        x=2^3=8   | x=2^4=16  |x=2^5=32
    st=x/2=2/2=1               st=4/2=2        st=8/2=4  | st=8      |st=16
    y=(20+1)/2=10              y=(20+2)/4=5    y=(20+4)/8|y=(20+8)/16|y=(20+16)/32
                                                =3       |  =1       | =1

here we can see that for n=20, we can make only 5 groups. 
which is equals to log2(n)+1==log2(20)+1=4+1==5
so we'll loop through 1 to log2(n)+1 where i will be our group number. 

now suppose k=17
when i=1,x=2^1=2 & st=2/2=1 & y=(n+st)/x=(20+1)/2=10 < 17
so k=17-10=7 & i++

now  i=2, x=2^2=4 & st=4/2=2 & y=(20+2)/4=5 < 7
so k=7-5=2 & i++

now i=3, x=2^3=8 & st=8/2=4 & y=(20+4)/8=3 > 2
here if condition matched, since k!=1 so inner else condition will
be executed where ans=4+(2-1)*8=4+1*8=4+8=12 
so 12 is the final answer.
*/

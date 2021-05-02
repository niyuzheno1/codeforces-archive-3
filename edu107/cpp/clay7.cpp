//no-unlocked
const int MN = 3d5+2;
int n,m;
char a[MN];
int I(int x, int y){
    return x*m + y;
}
#define A(x,y) a[I(x,y)]
{
    rd(n,m);
    rep(i,n){
        char * tmp =  & A(i,0);
        rd(tmp);
    }
    
}
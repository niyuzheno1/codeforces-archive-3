//no-unlocked
int Tcases;
int n;
char grid[310][310];
{
    rd(Tcases);
    rep(Tcases){
        rd(n);
        rep(i,n){
            rd(grid[i]);
        }
        int b[3] = {0,0,0};
        int w[3] = {0,0,0};
        rep(i,n)
        {
            rep(j,n){
                if(grid[i][j] == 'X')
                    ++b[(i+j)%3];
                if(grid[i][j] == 'O')
                    ++w[(i+j)%3];
            }
        }
        int idx1 = argmin(b(3));
        int idx2 = -1;
        rep(i,3){
            if(i == idx1) continue;
            if(idx2 == -1 || w[idx2] > w[i]) idx2 = i;
        }
        int scheme1 = b[idx1] + w[idx2];
        int idx3 = argmin(w(3));
        int idx4 = -1;
        rep(i,3){
            if(i == idx3) continue;
            if(idx4 == -1 || b[idx4] > b[i]) idx4 = i;
        }
        int scheme2 = w[idx3]+b[idx4];
        if(scheme1 > scheme2){
            idx1 = idx4;
            idx2 = idx3;
        }
       
        rep(i,n)
            rep(j,n){
                if((i+j)%3 == idx1 && grid[i][j] == 'X'){
                    grid[i][j] = 'O';
                }
                else if((i+j)%3 == idx2 && grid[i][j] == 'O'){
                    grid[i][j] = 'X';
                }
            }
        rep(i,n){
            wt(grid[i]);
        }
    }
}
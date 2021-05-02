//no-unlocked
{
    REP(rd_int()){
        int @a,@b, @c;
        ll cmd = 2;
        while(true){
           auto x = to_string(cmd);
           if(x.length() >= c) break;
           cmd <<= 1; 
        }
        ll x,y;
        x = y = cmd;
        while(true){
            auto xx = to_string(x);
            if(xx.length() >= a) break;
            x <<=1;
        }
        
        while(true){
            auto xx = to_string(y);
            if(xx.length() >= b) break;
            y *=3;
        }
        wt(x,y);
    }
}
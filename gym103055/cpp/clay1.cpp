//no-unlocked
ll b[5], r[5];
{
    rd(b(5), r(5));
    ll x = sum(b(5))+1;
    ll y = sum(r(5));
    if(x > y) wt("Blue");
    else wt("Red");
}
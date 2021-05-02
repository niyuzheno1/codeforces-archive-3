//no-unlocked
double a, b, c, d;
{
    rd(a,b,c,d);
    double l = a/b;
    double e = c/d;
    wt(l * (1.0/(1.0-(1.0-l)*(1.0-e))));

}

string Solution::fractionToDecimal(int n, int d) {

    long long p=n;
    long long deno=d;
    long long q;
    long long quot;
    bool neg=0;
    if(p<0){
        neg=1;
        p=0-p;
    }
    if(d<0){
        if(!neg)
            neg=1;
        else neg=0;
        deno=0-deno;
    }
    string s="";
    if(p==0){
        s.append("0");
        return s;
    }
    if(neg)
        s.append("-");
    q=p/deno;
    s.append(to_string(q));
    if(p%d==0)
        return s;
    s.append(".");
    int j=s.length();
    p=p%deno;
    unordered_map<int,int> mymap;
    bool repeat=0;
    while(p>0 && !repeat){
        p*=10;
        if(mymap.find(p)!=mymap.end()){
            j=mymap[p];
            repeat=1;
            break;
        }
        else{
            mymap[p]=s.length();
        }
        q=p/deno;
        s.append(to_string(q));
        p=p%deno;
    }
    if(repeat){
        s.append(")");
        s.insert(j,"(");
    }
    return s;
}

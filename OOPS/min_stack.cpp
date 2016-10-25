MinStack::MinStack() {

    vector<pair<int,int> > vs(10000);
    int mn = INT_MIN;
    int point = 0;
    int pos = 0;
}

void MinStack::push(int x) {
    vs[point].first = x;
    if (x>mn){
        if (point==0){
            mn = x;
        }
        vs[point].second = pos;
    }
    else{
        vs[point].second = point;
        pos = point;
        mn = x;
    }
    point++;

}

void MinStack::pop() {
    if (point!=0)
        point--;
}

int MinStack::top() {
    if (point!=0)
        return vs[point-1].first;
    else
        return -1;
}

int MinStack::getMin() {
    if (point!=0)
        return vs[vs[point-1].second].first;
    else
        return -1;
}





class SegTree{
    public:
        int n;
        int *tree;

        SegTree(int nn){
            n=nn;
            tree=new int[5*nn+5];
            memset(tree,0,sizeof(tree));
            build(0,n-1,0);
        }

        int build(int l,int r,int i){
            if(l>r) return 0;
            if(l==r) {
                tree[i]=1;
                return 1;
            }
            int mid=(l+r)/2;
            int L=build(l,mid,left(i));
            int R=build(mid+1,r,right(i));
            tree[i]=L+R;
            return tree[i];
        }

        int update(int i,int value,int l,int r,int index){
            if(l>r) return 0;
            if(l==r) {
                tree[index]=value;
                return value;
            }
            int mid=(l+r)/2;
            int L=0,R=0;
            if(i<=mid) L=update(i,value,l,mid,left(index));
            else R=update(i,value,mid+1,r,right(index));

            return tree[index]=tree[left(index)] + tree[right(index)];
        }

        int query(int spaces,int l,int r,int i){
            if(l>r) return -1;
            int left_spaces=tree[left(i)];
            int right_spaces=tree[right(i)];

            if(l==r) return l;

            if(left_spaces>=spaces) {
                return query(spaces,l,(l+r)/2,left(i));
            }
            else {
                return query(spaces-left_spaces,(l+r)/2+1,r,right(i));
            }
        }

        int left(int i){
            return 2*i+1;
        }

        int right(int i){
            return 2*i+2;
        }
};

vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {

    vector< pair<int,int> > v;
    int n=heights.size();
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        v.push_back(make_pair(heights[i],infronts[i]));
    }

    sort(v.begin(),v.end());

    SegTree s(n);

    for(int i=0;i<n;i++){
        int index=s.query(v[i].second+1,0,n-1,0); // where is v[i].second th empty position
        ans[index]=v[i].first;
        //cout<<index<<endl;
        s.update(index,0,0,n-1,0);
    }

    return ans;
}

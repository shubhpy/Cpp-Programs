/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    int done = 0;
    int change = 0;
    while(!done){
        change = 0;
        for(int i = 1;i<n;i++){
            if (p[i].second<p[i-1].second){
                change = 1;
                int j = i-1;
                int k = i;
                while(k>=0 && p[k].second<p[j].second){
                    struct val temp = p[k];
                    p[k] = p[j];
                    p[j] = temp;
                    k--;
                    j--;
                }
            }
        }
        if (!change){
            done = 1;
        }
    }
    int ans = 1;
    int last = p[0].second;
    for(int i = 1;i<n;i++){
        if (p[i].first > last){
            ans++;
            last = p[i].second;
        }
    }

    return ans;
}

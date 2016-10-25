
// A C++ program implementing the above design
#include<bits/stdc++.h>
#define max_color 100005
#define maxn 100005
#define LL long long int
using namespace std;

// Note: All elements of global arrays are
// initially zero
// All the arrays have been described above
vector<int> bit[maxn];
vector<int> vis_time[maxn];
vector<int> end_time[maxn];
vector<int> flat_tree[2 * maxn];
vector<int> tree[maxn];
vector<int> table[max_color];
vector<int> traverser[max_color];
vector<int> ans[maxn];
vector< pair< pair<int, int>, int> > queries;
vector<bool> vis[maxn];
int tim = 0;

LL res = 0;

//li, ri and index are stored in queries vector
//in that order, as the sort function will use
//the value li for comparison


//ans[i] stores answer to ith query


//update function to add val to idx in BIT
void update(int idx, int val)
{
	while ( idx < maxn )
	{
		bit[idx] += val;
		idx += idx & -idx;
	}
}

//query function to find sum(1, idx) in BIT
int query(int idx)
{
	int res = 0;
	while ( idx > 0 )
	{
		res += bit[idx];
		idx -= idx & -idx;
	}
	return res;
}

void dfs(int v, vector<LL> &color)
{
	//mark the node visited
	vis[v] = 1;

	//set visiting time of the node v
	vis_time[v] = ++tim;

	//use the color of node v to fill flat_tree[]
	flat_tree[tim] = color[v];

	vector<int>::iterator it;
	for (it=tree[v].begin(); it!=tree[v].end(); it++)
		if (!vis[*it])
			dfs(*it, color);


	// set ending time for node v
	end_time[v] = ++tim;

	// setting its color in flat_tree[] again
	flat_tree[tim] = color[v];
}

//function to add an edge(u, v) to the tree
void addEdge(int u, int v)
{
	tree[u].push_back(v);
	tree[v].push_back(u);
}

//function to build the table[] and also add
//first occurrences of elements to the BIT
void hashMarkFirstOccurences(int n)
{
	for (int i = 1 ; i <= 2 * n ; i++)
	{
		table[flat_tree[i]].push_back(i);

		//if it is the first occurence of the element
		//then add it to the BIT and increment traverser
		if (table[flat_tree[i]].size() == 1)
		{
			//add the occurence to bit
			update(i, 1);

			//make traverser point to next occurence
			traverser[flat_tree[i]]++;
		}
	}
}

//function to process all the queries and store thier answers
void processQueries()
{
	int j = 1;
	for (int i=0; i<queries.size(); i++)
	{
		//for each query remove all the ocurences before its li
		//li is the visiting time of the node
		//which is stored in first element of first pair
		for ( ; j < queries[i].first.first ; j++ )
		{
			int elem = flat_tree[j];

			//update(i, -1) removes an element at ith index
			//in the BIT
			update( table[elem][traverser[elem] - 1], -1);

			//if there is another occurrence of the same element
			if ( traverser[elem] < table[elem].size() )
			{
				//add the occurrence to the BIT and
				//increment traverser
				update(table[elem][ traverser[elem] ], 1);
				traverser[elem]++;
			}
		}

		//store the answer for the query, the index of the query
		//is the second element of the pair
		//And ri is stored in second element of the first pair
		ans[queries[i].second] = query(queries[i].first.second);
	}
}

// Count distinct colors in subtrees rooted with qVer[0],
// qVer[1], ...qVer[qn-1]
void countDistinctColors(vector<LL> &color, int n, vector<int> qVer, int qn)
{
	// build the flat_tree[], vis_time[] and end_time[]
	tree[qVer[0]].erase(remove(tree[qVer[0]].begin(), tree[qVer[0]].end(),qVer[1]), tree[qVer[0]].end());
	tree[qVer[1]].erase(remove(tree[qVer[1]].begin(), tree[qVer[1]].end(),qVer[0]), tree[qVer[1]].end());


	dfs(qVer[0], color);
	dfs(qVer[1], color);

	// add query for u = 3, 2 and 7
	for (int i=0; i<qn; i++)
		queries.push_back(make_pair(make_pair(vis_time[qVer[i]],
									end_time[qVer[i]]), i) );

	// sort the queries in order of increasing vis_time
	sort(queries.begin(), queries.end());

	// make table[] and set '1' at first occurences of elements
	hashMarkFirstOccurences(n);

	// process queries
	processQueries();
    cout <<  ans[0] << " " << ans[1]  << "\n";
    res = res  + (ans[0]*ans[1]);

	addEdge(qVer[0],qVer[1]);
}

//driver code
int main()
{

    int n;
    cin >> n;
    vector<LL> color(n+1);
    color[0] = 0;
    for(int i = 1;i<=n;i++){
        cin >> color[i];
    }
    int a,b;
    vector<vector<int> > e(n-1,vector<int>(2));
    for(int i = 0;i<n-1;i++){
        cin >> a >> b;
        e[i][0]= a;
        e[i][1]= b;
        addEdge(a,b);
    }

    for(int i = 0;i<n-1;i++){
        /*bit.clear();
        vis_time.clear();
        end_time.clear();
        flat_tree.clear();
        tree.clear();
        table.clear();
        traverser.clear();
        ans.clear();
        queries.clear();
        vis.clear();
        tim = 0;
        */
        countDistinctColors(color, n,e[i],2);
    }

    cout << res;
	return 0;
}

// Print all palindromes of size
// greater than equal to 3 of a given
// string. (DP)

#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Q: checking palindrome does not consider
//    space, case insensitive, right?
// A: True.


long long int bhejo(vector<vector<bool> > &F,int i,int j){

    }

int checkPalindrome(string s) {
	if (s.size()==1){
        return 1;
	}
	else  if(s.size()==2){
        if (s[0]==s[1]){
            return 2;
        }
        else{
            return 1;
        }
	}
	int N = s.size();
	vector<vector<bool> > F(N,vector<bool>(N));
	int u,v;
	for (int k=0; k<N;   k++){
	    for (int i=0;  i<N-k; i++){
            u = i;
            v = i+k;
            if (u==v){
                F[u][v]=1;
            }
            else if(v==u+1){
                F[u][v]= s[u]==s[v];
            }
            else if( v>=u+2){
                if (s[u]==s[v]){
                    F[u][v]=F[u+1][v-1];
                }
                else{
                    F[u][v]=0;
                }
            }
}
}

for (int k=0; k<N;   k++){
	    for (int i=0;  i<N; i++){
	    cout << F[i][k] << " ";
	    }
	    cout << "\n";
}

}

    long long int p=1;
	for(int i=0;i>=0;i--){
        for(int j=0;j>s.size()-1;j++){
            if (F[i][j]==1){
                p = p*(1+bhejo(F,i -(l -j),l-j));

            }
        }
	}

}

*/

int main() {
	// string s = "122112321";
	//string s = "cabbaabbacasdasdsdsdsdassadsadasdasadsadasda";
	string s = "bobseesanna";
	checkPalindrome(s);

	return EXIT_SUCCESS;
}


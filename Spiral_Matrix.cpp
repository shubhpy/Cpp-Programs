#include <iostream>
#include<vector>
using namespace std;


void solve(vector<vector<int> > &vect,int f,int e){
    bool done = false;
    int j;
    for(int i =f;i<e;i++){
        if (!done){
        for(j =f ;j<e;j++){
            cout <<  vect[i][j]  << " " ;
            done = true;
        }
        }
        else{
            cout <<  vect[i][j]  << " " ;
        }
    }
}

int main() {
	//code
	int T;
	cin >> T;
	//vector<vector<int> > vect;
	vector<vector<int> > vect(4, vector<int>(4,0));
	for(int i=0;i<4;i++){
	    for(int j=0;j<4;j++){
	    cin >> vect[i][j];
	    }
	}

	for(int i=0;i<4;i++){
	    for(int j=0;j<4;j++){
	    cout <<  vect[i][j] << " ";
	    }
	}

	solve(vect,0,3);


	return 0;
}

#include <iostream>
#include<vector>
using namespace std;

int main() {
	int T,N,i;
	cin >> T;
	for(i=0;i<T;i++){
	cin >> N;
	vector<char> vect(N);
	for(int j=0;j<N;j++){
	    cin >> vect[j];
	}
	vector<int> vect2(26);
	for(int k=0;k<N;k++){
	    vect2[(int) vect[k] - (int) 'a']++;
	}
	int found = 0;
	for(int l=0;l<N;l++){
	    if (vect2[(int) vect[l] - (int) 'a']==1){
	        cout <<(char) (l+ (int)'a') << "\n";
	        found=1;
	        break;
	    }
	}
	if (found==0){
	    cout << -1 << "\n";
	}
	}


	return 0;
}

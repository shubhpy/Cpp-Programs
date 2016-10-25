#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	string m = "milly";
	string S;

	for(int t = 0;t<T;t++){
		cin >> S;
		int j = 0;
		for(int i = 0;i<S.length();i++){
			if (S[i]==m[j]){
					j++;
				}

			if (j==5){
				break;
			}
		}

		if (j==5){
			cout << "Milly is Intelligent\n";
		}
		else{
			cout << "Milly is not Intelligent\n";
		}
	}

	return 0;
}

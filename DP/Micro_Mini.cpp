#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t = 0;t<T;t++){
		string s;
		cin >> s;
		int diff = 0;
		int l = s.length();
		if (l%2==1){
			cout << l << "\n";
		}
		else{
			int i = 0;
			int ans = l;
			for(int j = l/2;j>=1;j--){
				int check = 1;
				while(i<l-j){
					if (s[i]!=s[i+j]){
						check = 0;
						break;
					}
					i++;
				}
				if (check){
					ans = min(ans,j);
				}
			}
			cout << ans << "\n";
		}
	}
    return 0;
}

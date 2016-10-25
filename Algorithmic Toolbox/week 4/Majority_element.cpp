#include <iostream>
#include <vector>

using std::vector;
using std::swap;

int findCandidate(vector<int> a , int size)
{
    int maj_index = 0, count = 1;
    int i;
    for(i = 1; i < size; i++)
    {
        if(a[maj_index] == a[i])
            count++;
        else
            count--;
        if(count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    count = 0;
    for(i = 0; i < size; i++)
    {
        if(a[maj_index] == a[i])
        {
        count++;
        }
    }
    /*std::cout << a[maj_index] << " " << count;
*/
    if (count>size/2){
        return 1;
    }
    else{
        return 0;
        }
    }

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }

  std::cout << findCandidate(a,n);
  }

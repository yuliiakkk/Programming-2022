#include <iostream> 
#include <vector>
using namespace std;
int main() 
    {

	int n, a0;
	vector<int> arr1, arr2; 
	cin >> n;
	cin >> a0;
	arr2.push_back(a0);
	for (int i = 1; i < n; i++)
	{
		int ai;
		cin >> ai;

		if (ai > a0)
		{
			arr1.push_back(ai);
		}
		else
		{
			arr2.push_back(ai);
		}
	}

		arr1.insert(arr1.end(), arr2.begin(), arr2.end());


		for (int i = 0; i < n; i++)
		{
			cout << arr1[i] << " ";
		}
		return 0;
	}
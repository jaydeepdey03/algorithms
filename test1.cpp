// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     vector<vector<int, int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     reverse(mat.begin(), mat.end());
//     for(auto i: mat){
//         for(auto j: i){
//             cout << j << endl;
//         }
//     }
//     return 0;
// }

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

int parity(int a)
{
	return a % 3;
}

int solve(int array[], int size)
{
	int operations = 0;
	for (int i = 0; i < size - 1; i++) {
		if (parity(array[i]) == parity(array[i + 1])) {

			operations++;
			if (i + 2 < size) {
				int pari1 = parity(array[i]);
				int pari2 = parity(array[i + 2]);
				if (pari1 == pari2) {
					if (pari1 == 0)
						array[i + 1] = 1;
					else if (pari1 == 1)
						array[i + 1] = 0;
					else
						array[i + 1] = 1;
				}
				else {
					if ((pari1 == 0 && pari2 == 1)
						|| (pari1 == 1 && pari2 == 0))
						array[i + 1] = 2;
					if ((pari1 == 1 && pari2 == 2)
						|| (pari1 == 2 && pari2 == 1))
						array[i + 1] = 0;
					if ((pari1 == 2 && pari2 == 0)
						|| (pari1 == 0 && pari2 == 2))
						array[i + 1] = 1;
				}
			}
		}
	}

	return operations;
}

// Driver Code
int main()
{
	int array[] = { 2, 1, 3, 0 };
	int size = sizeof(array) / sizeof(array[0]);
	cout << solve(array, size) << endl;

return 0;
}

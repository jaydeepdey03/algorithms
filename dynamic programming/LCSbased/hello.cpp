#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string s1 = "ABC";
    string s2(s1);

    reverse(s1.begin(), s1.end());

    cout << s1 << " " << s2 << endl;
    return 0;
}
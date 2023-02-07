#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;

int minimumKeypadClickCount(string text)
{
    // unordered_set<char> uniqueChar;
    int keyboardClickCount = 0;
    // for(int i = 0; i<text.length; i++){
    //     uniqueChar.insert(text[i]);
    // }

    // for(int i = 10; i<; i++){
    //     if(uniqueChar.find(text[i]) == uniqueChar.end()){

    //     }
    // }

    map<char, int> m;
    map<char, int>::iterator itr;
    for (long i = 0; i < text.length(); i++)
    {
        m[text[i]]++;
    }

    int count = 0;
    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
        advance(itr, 9);
    }

    return count;
}

int main()
{
    string s = "abcghdiefjoba";
    cout << minimumKeypadClickCount(s) << endl;
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    string a="abcz";
    string b="azdb";
    int i=0;
    int j=0;
    while(i<a.size() && j<b.size())
    {
        if(a[i]==b[j])
        {
            i+=1;
            if(i!=a.size())
            {
                j++;
            }

        }
        else{
            i+=1;
        }
    }
    cout<<i-j<<endl;
    return 0;
}
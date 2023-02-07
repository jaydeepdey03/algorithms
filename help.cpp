#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<string>pixels;
    pixels.push_back("1010");
    pixels.push_back("0101");
    pixels.push_back("1010");
    for(int i=0;i<pixels.size();i++)
    {
        for(int j=0;j<4;j++)
        {
            int dsum1=0;
            int dsum0=0;
            int rsum1=0;
            int rsum0=0;
            cout<<pixels[0][0]<<endl;
            for(int k=j;k<pixels.size();k++)
            {
                if(pixels[k][i]=='1')
                {
                    dsum1+=1;
                }
                dsum0+=1;
            }
            for(int k=j;k<4;k++)
            {
                if(pixels[i][k]=='1')
                {
                    rsum1+=1;
                }
                rsum0+=1;
            }
            cout<<(rsum1+dsum1)-(rsum0+dsum0)<<endl;

        }
    }
    
    return 0;
}
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool repeatedSubstringPattern(string s)
{
    int n = s.size();

    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            int times = n / i;

            string pattern = s.substr(0, i);
            string newstr = "";
            while (times--)
            {
                newstr += pattern;
            }
            if (newstr == s)
                return 1;
        }
    }

    return 0;
}
    int main()
    {
string s;
cin>>s;
 bool result=repeatedSubstringPattern(s);
 if(result){
    cout<<"1"<<"";
 }
 else
 cout<<"0";

    return 0;
    }
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
int compress(vector<char> &chars)
{
    int n = chars.size();
    int index = 0;
    int i = 0;

    while (i < n)
    {
        char curr = chars[i];
        int count = 0;

        while (i < n && chars[i] == curr)
        {
            i++;
            count++;
        }

        chars[index] = curr;
        index++;

        if (count > 1)
        {
            string countstr = to_string(count);
            for (char ch : countstr)
            {
                chars[index] = ch;
                index++;
            }
        }
    }
    return index;
}

int main()
{
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    cout << "Enter characters (space separated): ";
    for (int i = 0; i < n; i++)
    {
        cin >> chars[i];
    }

    int newLength = compress(chars);

    cout << "Compressed Length: " << newLength << endl;
    cout << "Compressed Characters: ";
    for (int i = 0; i < newLength; i++)
    {
        cout << chars[i] << " ";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
//Playfair cipher (treating X as uncommon letter and assuming I & J are interchangeable)
class PlayfairCipher
{
  private:
    char key[5][5];
    map<char, pair<int, int> > keymap;

  public:
    PlayfairCipher(const string s)
    {
        int c, k, i = 0, j = 0, n = s.size();
        bool a[26] = {0};
        key[0][0] = s[0];
        a[s[0] - 65] = 1;
        for (k = 1; k < n; k++)
        {
            c = s[k] - 65;
            if (!a[c])
            {
                j++;
                if (j >= 5)
                {
                    j = 0;
                    i++;
                }
                key[i][j] = s[k];
                a[c] = 1;
                if (c == 8 || c == 9)
                    a[8] = a[9] = 1;
            }
        }
        for (c = 0; c < 26; c++)
        {
            if (!a[c])
            {
                j++;
                if (j >= 5)
                {
                    j = 0;
                    i++;
                }
                key[i][j] = char(c + 65);
                a[c] = 1;
                if (c == 8 || c == 9)
                    a[8] = a[9] = 1;
            }
        }
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
                keymap[key[i][j]] = make_pair(i, j);
        }
    }
    string encrypt(string s)
    {
        int i, row1, row2, col1, col2, n = s.size();
        string res = "";
        char prev = s[0];
        res += prev;
        for (i = 1; i < n; i++)
        {
            if (prev == s[i])
                res += "X";
            res += s[i];
            prev = s[i];
        }
        if (res.size() % 2)
            res += "X";
        s = res;
        res = "";
        n = s.size();
        for (i = 0; i < n; i += 2)
        {
            row1 = keymap[s[i]].first;
            col1 = keymap[s[i]].second;
            row2 = keymap[s[i + 1]].first;
            col2 = keymap[s[i + 1]].second;
            if (row1 == row2)
            {
                col1 = (col1 + 1) % 5;
                col2 = (col2 + 1) % 5;
            }
            else if (col1 == col2)
            {
                row1 = (row1 + 1) % 5;
                row2 = (row2 + 1) % 5;
            }
            else
            {
                swap(col1, col2);
            }
            res += key[row1][col1];
            res += key[row2][col2];
        }
        return res;
    }
    string decrypt(string s)
    {
        int i, row1, row2, col1, col2, n = s.size();
        string res = "";
        for (i = 0; i < n; i += 2)
        {
            row1 = keymap[s[i]].first;
            col1 = keymap[s[i]].second;
            row2 = keymap[s[i + 1]].first;
            col2 = keymap[s[i + 1]].second;
            if (row1 == row2)
            {
                col1 = (col1 + 4) % 5;
                col2 = (col2 + 4) % 5;
            }
            else if (col1 == col2)
            {
                row1 = (row1 + 4) % 5;
                row2 = (row2 + 4) % 5;
            }
            else
            {
                swap(col1, col2);
            }
            res += key[row1][col1];
            res += key[row2][col2];
        }
        return res;
    }
};
int main()
{
    string key = "PLAYFAIREXAMPLE", text = "HIDETHEGOLDINTHETREESTUMP";
    PlayfairCipher c(key);
    string cipher = c.encrypt(text);
    cout << "Plain Text : " << text;
    cout << "\nKey: " << key;
    cout << "\nCipher Text: " << cipher;
    cout << "\nDecrypted Text: " << c.decrypt(cipher);  // Still any X that doesnot make sense should be removed
    return 0;
}
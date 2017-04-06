#include <bits/stdc++.h>
using namespace std;
class InvalidKeyException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nKey invalid\n";
    }
};
class MonoalphabeticCipher
{
  private:
    string enc_key, dcr_key;

  public:
    MonoalphabeticCipher(const string s)
    {
        int i, n = s.size(), a[26] = {0};
        if (n != 26)
        {
            InvalidKeyException e;
            throw e;
        }
        else
        {
            for (i = 0; i < 26; i++)
                a[s[i] - 'A']++;
            for (i = 0; i < 26; i++)
            {
                if (a[i] != 1)
                {
                    InvalidKeyException e;
                    throw e;
                }
            }
            enc_key = dcr_key = s;
            for (i = 0; i < 26; i++)
            {
                dcr_key[s[i] - 'A'] = 'A' + i;
            }
        }
    }
    string encrypt(const string s)
    {
        int i, n = s.size();
        string res = "";
        for (i = 0; i < n; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                res += enc_key[s[i] - 'A'];
            else
                res += s[i];
        }
        return res;
    }
    string decrypt(const string s)
    {
        int i, n = s.size();
        string res = "";
        for (i = 0; i < n; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                res += dcr_key[s[i] - 'A'];
            else
                res += s[i];
        }
        return res;
    }
};
int main()
{
    string key = "EJFMXNQOLPYRWTGVSUZAHBKCID", text = "ATTACKATONCE";
    MonoalphabeticCipher c(key);
    string cipher = c.encrypt(text);
    cout << "Plain Text : " << text;
    cout << "\nKey: " << key;
    cout << "\nCipher Text: " << cipher;
    cout << "\nDecrypted Text: " << c.decrypt(cipher);
    return 0;
}
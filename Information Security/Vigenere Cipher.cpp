//Vigenère Cipher
#include <iostream>
using namespace std;
class VigenereCipher
{
  private:
    string key;

  public:
    VigenereCipher(const string s)
    {
        key = s;
    }
    string generateKey(const string s)
    {
        string keyword = key;
        int i = 0, x = s.size();
        while (keyword.size() != s.size())
        {
            if (x == i)
                i = 0;
            keyword += keyword[i++];
        }
        return keyword;
    }
    string encrypt(const string s)
    {
        int i, x, n = s.size();
        string res = "", keyword = generateKey(s);
        for (i = 0; i < n; i++)
        {
            x = (s[i] + keyword[i]) % 26;
            x += 'A';
            res += x;
        }
        return res;
    }
    string decrypt(const string s)
    {
        int i, x, n = s.size();
        string res = "", keyword = generateKey(s);
        for (i = 0; i < s.size(); i++)
        {
            x = (s[i] - keyword[i] + 26) % 26;
            x += 'A';
            res += x;
        }
        return res;
    }
};
int main()
{
    string key = "TESTKEY", text = "ATTACKATONCE";
    VigenereCipher c(key);
    string cipher = c.encrypt(text);
    cout << "Plain Text : " << text;
    cout << "\nKey: " << key;
    cout << "\nCipher Text: " << cipher;
    cout << "\nDecrypted Text: " << c.decrypt(cipher);
    return 0;
}
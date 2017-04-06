#include <iostream>
using namespace std;
class CaesarCipher
{
  private:
    unsigned int key;

  public:
    CaesarCipher(unsigned int n = 3)
    {
        key = n;
    }
    string encrypt(const string s)
    {
        string res = "";
        int i, n = s.size();
        for (i = 0; i < n; i++)
        {
            if (isupper(s[i]))
                res += char(int(s[i] + key - 65) % 26 + 65);
            else
                res += char(int(s[i] + key - 97) % 26 + 97);
        }
        return res;
    }
    string decrypt(const string s)
    {
        string res = "";
        int i, n = s.size();
        for (i = 0; i < n; i++)
        {
            if (isupper(s[i]))
                res += char(int(s[i] - key - 65) % 26 + 65);
            else
                res += char(int(s[i] - key - 97) % 26 + 97);
        }
        return res;
    }
};
int main()
{
    unsigned int s = 4;
    CaesarCipher c(s);
    string text = "ATTACKATONCE", cipher = c.encrypt(text);
    cout << "Plain Text : " << text;
    cout << "\nShift: " << s;
    cout << "\nCipher Text: " << cipher;
    cout << "\nDecrypted Text: " << c.decrypt(cipher);
    return 0;
}
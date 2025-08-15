#include <iostream>
#include <vector>
using namespace std;

class User
{
private:
    string username,password;
    vector<string> listUser,listPassword;
    void setUsername(string inputUsername){
        int lengthUsername = inputUsername.length();

        if (lengthUsername >= 6)
        {
            username = inputUsername;
        }
        else{
            cout << "Try Again!!" << endl;
        }
    }
    void setPassword(string inputPassword){
        int lengthPassword = inputPassword.length();

        if (lengthPassword >= 6)
        {
            password = inputPassword;
        }
        else{
            cout << "Try Again!!" << endl;
        }
    }
public:

    void signUp(string inputUsername, string inputPassword){
        int lengthList = listUser.size();

        for (int i = 0; i < lengthList; i++)
        {
            if (inputUsername == listUser[i])
            {
                cout << "This Username is already used, Try Again!" << endl;
                return;
                
            }
        }
        setUsername(inputUsername);
        setPassword(inputPassword);
        listUser.push_back(username);
        listPassword.push_back(password);
        cout << "Sign Up Success!!" << endl;
        
    }

    void signIn(string inputUsername, string inputPassword){
        int lengthList = listUser.size();
        for (int i = 0; i < lengthList; i++)
        {
            if (inputUsername == listUser[i] && inputPassword == listPassword[i])
            {
                
                cout << "Sign In Success!!" << endl;
                return;
            }
            else
            {
                cout << "The Username is doesnt exists or password is wrong, Try Again" << endl;
            }
            
        }
        
    }

};

int main(int argc, char const *argv[])
{
    User user1;
    user1.signUp("giwnk__", "070906"); // sukses daftar
    user1.signIn("giwnk__", "070906"); // sukses login
    user1.signIn("giwnk__", "123456"); // gagal login (error 1x saja)
    user1.signUp("giwnk__", "070906"); // username sudah dipakai
    return 0;
}

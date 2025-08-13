#include <iostream>
using namespace std;

class CharacterGame{
    public:
    // Attributes
        int level;
        string name,role;

    // Constructor
        CharacterGame (string inputName, string inputRole){
            name = inputName;
            role = inputRole;
            level = 1;
        }

    // Methods
        int levelUp(){
            return level += 1;
        }

        void showStatus(){
            cout << "Character Name: " << name << endl;
            cout << "Character Role: " << role << endl;
            cout << "Character Level: " << level << endl;
        }
};

int main(int argc, char const *argv[])
{
    int level;
    string name,role;

    cout << "Input Your Name Character: ";
    cin >> name;

    cout << "Input Your Role Character: ";
    cin >> role;

    CharacterGame char1(name,role);

    char1.showStatus();
    char1.levelUp();
    char1.showStatus();

    return 0;
}

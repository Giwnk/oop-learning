#include <iostream>
using namespace std;

class GameCharacter{
    public:
        string name,role;
        int level;
};

int main(int argc, char const *argv[])
{
    GameCharacter character1;

    character1.name = "Steve";
    character1.role = "Archer";
    character1.level = 0;

    cout << character1.name << endl;
    cout << character1.role << endl;
    cout << character1.level << endl;

    return 0;
}

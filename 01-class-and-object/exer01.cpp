#include <iostream>
using namespace std;

class GameCharacter{
    public:
        string name,role;
        int level = 0;
};

int main(int argc, char const *argv[])
{
    GameCharacter character1;

    character1.name = "Steve";
    return 0;
}

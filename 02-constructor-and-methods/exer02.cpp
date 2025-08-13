#include <iostream>
using namespace std;

class CharacterGame{
    public:
    // Attributes
        int level,hp,atk;
        string name,role;

    // Constructor
        CharacterGame (string inputName, string inputRole, int inputAtk){
            name = inputName;
            role = inputRole;
            atk = inputAtk;
            level = 1;
            hp = 100;
        }

    // Methods
        void levelUp(){
            level += 1;
            atk += 10;
        }

        bool isKo(){
            return hp <= 0; 
        }

        void attackEnemy(CharacterGame &enemy){
            cout << name << " Attacking " << enemy.name << " And Reduce " << atk << " HP!" << endl;
            enemy.hp -= atk;
            cout << enemy.name << " Has " << enemy.hp << " Now" << endl;
            
        }

        void showStatus(){
            cout << "Character Name: " << name << endl;
            cout << "Character Role: " << role << endl;
            cout << "Character Level: " << level << endl;
        }
};

int main(int argc, char const *argv[])
{   

    CharacterGame char1("Giwank","Archer",30);
    CharacterGame char2("Naya", "Fighter", 20);

    char1.showStatus();
    char2.showStatus();

    while (true) // hp <= 0;
    {
        if (!char2.isKo())
        {
            char1.attackEnemy(char2);
        }
        else
        {   
            cout << "Your Enemy Is KO, Level Up!!" << endl;
            char1.levelUp();
            break;
        }   
    }

    char1.showStatus();

    return 0;
}

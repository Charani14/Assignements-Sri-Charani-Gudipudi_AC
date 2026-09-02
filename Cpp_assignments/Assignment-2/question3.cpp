#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int level = 1;

class Entity {
private:
    string name;
    int health;
    int level;
    string type;

public:
    Entity()
        : name("Unknown"), health(0), level(0), type("Unknown") {
    }

    Entity& setName(const string& name) {
        this->name = name;
        return *this;
    }

    Entity& setHealth(int health) {
        this->health = health;
        return *this;
    }

    Entity& setLevel(int level) {
        this->level = level;
        return *this;
    }

    Entity& setType(const string& type) {
        this->type = type;
        return *this;
    }

    string getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    int getLevel() const {
        return level;
    }

    string getType() const {
        return type;
    }

    void displayInfo() const {
        cout << "\nEntity Information" << endl;
        cout << "Name   : " << name << endl;
        cout << "Health : " << health << endl;
        cout << "Level  : " << level << endl;
        cout << "Type   : " << type << endl;
    }
};

namespace Physics {

    double clamp(double val, double min, double max) {
        if (val < min)
            return min;

        if (val > max)
            return max;

        return val;
    }

    double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }
}

namespace GameMath {

    int clamp(int val, int min, int max) {
        if (val < min)
            return min;

        if (val > max)
            return max;

        return val;
    }

    double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }
}
namespace Engine {
    namespace Audio {

        void playSound(string name) {
            cout << "Playing: " << name << endl;
        }

    }
}

int main() {

    Entity player;
    Entity enemy;
    Entity item;

    player.setName("Aragorn")
           .setHealth(100)
           .setLevel(10)
           .setType("Player");

    enemy.setName("Orc")
          .setHealth(60)
          .setLevel(5)
          .setType("Enemy");

    item.setName("HealthPotion")
         .setHealth(0)
         .setLevel(1)
         .setType("Item");

    cout << "===== ENTITY SYSTEM =====" << endl;

    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();

    cout << "\n===== NAMESPACE DEMONSTRATION =====" << endl;

    double velocity = 150.5;

    cout << "Physics clamp : "
         << Physics::clamp(velocity, 0.0, 100.0)
         << endl;

    cout << "GameMath clamp : "
         << GameMath::clamp(120, 0, 100)
         << endl;

    cout << "Physics lerp : "
         << Physics::lerp(0.0, 100.0, 0.5)
         << endl;

    cout << "GameMath lerp : "
         << GameMath::lerp(0.0, 200.0, 0.25)
         << endl;

    {
        using namespace Physics;

        cout << "Limited scope clamp : "
             << clamp(120.0, 0.0, 100.0)
             << endl;
    }

    int R, C;

    cout << "\n===== DYNAMIC GAME MAP =====" << endl;

    cout << "Enter number of rows: ";
    cin >> R;

    cout << "Enter number of columns: ";
    cin >> C;

    int** map = new int*[R];

    for (int i = 0; i < R; i++) {
        map[i] = new int[C];
    }

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            map[i][j] = rand() % 5;
        }
    }

    cout << "\n===== GAME MAP ("
         << R << " x "
         << C << ") =====\n";

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nLegend: "
         << "0=Grass "
         << "1=Water "
         << "2=Mountain "
         << "3=Forest "
         << "4=Dungeon"
         << endl;

    int tileCount[5] = {0};

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            tileCount[map[i][j]]++;
        }
    }

    cout << "\nTile Count:" << endl;
    cout << "Grass    : " << tileCount[0] << endl;
    cout << "Water    : " << tileCount[1] << endl;
    cout << "Mountain : " << tileCount[2] << endl;
    cout << "Forest   : " << tileCount[3] << endl;
    cout << "Dungeon  : " << tileCount[4] << endl;

    for (int i = 0; i < R; i++) {
        delete[] map[i];
    }

    delete[] map;

    cout << "\nDynamic map memory released successfully."
         << endl;

    int level = 10;

    cout << "\n===== SCOPE RESOLUTION =====" << endl;
    cout << "Local level  : " << level << endl;
    cout << "Global level : " << ::level << endl;

    cout << "\n===== AUDIO =====" << endl;
    Engine::Audio::playSound("sword_clash");

    return 0;
}
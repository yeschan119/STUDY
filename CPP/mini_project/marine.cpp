// define star craft marine's property & marine's activity
#include <iostream>

class Marine {
    int physical;     // marine physical
    int pos_x, pos_y; // marine position
    int damage;   // attack power
    bool is_dead;

    public:
        Marine();
        Marine(int x, int y);

        int attack();
        void be_attacked(int damage);
        void move(int x, int y);
        void show_status();
};

Marine::Marine() {
    physical = 50;
    pos_x = pos_y = 0;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y) {
    pos_x = x;
    pos_y = y;
    physical = 50;
    damage = 5;
    is_dead = false;
}

int Marine::attack() {return damage;}
void Marine::be_attacked(int damage) {
    physical -= damage;
    if (physical <= 0)
        is_dead = true;
}

void Marine::move(int x, int y) {
    pos_x = x;
    pos_y = y;
}

void Marine::show_status() {
    std::cout << "*** Marine ***" << std::endl;
    std::cout << "Location : ( " << pos_x << " , " << pos_y << " ) " << std::endl;
    std::cout << "Physical : " << physical << std::endl;
}

int main() {
    Marine marine1(2, 3);
    Marine marine2(3, 5);

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}

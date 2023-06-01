#include <iostream>
#include <string>

class Marine {
    int hp;     // marine physical strength
    int coord_x, coord_y;  // position of marine
    int damage;   // attack power
    bool is_dead;

    public:
        Marine();
        Marine(int x, int y);

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);

        void show_status();
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y)
{
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack(){return damage;}

void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0)
        is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "<< std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main ()
{
    Marine marine1(3, 5);
    Marine marine2(5, 10);

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
    
    return 0;
}
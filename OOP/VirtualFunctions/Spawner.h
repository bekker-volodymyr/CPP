#pragma once

#include <iostream>
#include <string>
#include "Enemy.h"

class Spawner {
public:
    Enemy* SpawnEnemy() {
        Enemy* ptr = nullptr;

        //srand(time(0));

        switch (rand() % 3)
        {
        case 0:
            ptr = new Swordsman(rand() % 25 + 1, 25, "Мечник");
            break;
        case 1:
            ptr = new Shooter(rand() % 70 + 1, 10, "Стрілець");
            break;
        case 2:
            ptr = new Bomber(rand() % 100 + 1, 5, "Мінометник");
            break;
        default:
            //ptr = new Enemy(0, 0, "Абстрактний ворог");
            break;
        }

        std::cout << ptr->getName() << " створений.\n";

        return ptr;
    }
};
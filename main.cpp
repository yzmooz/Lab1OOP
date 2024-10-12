#include "WateringRobot.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

// Тестирование:
int main() {
     //конструктора по умолчанию
    WateringRobot robot1;
    assert(robot1.getId() == "");
    assert(robot1.getVolume() == 0.0);
    assert(robot1.getWater() == 0.0);

    //  инициализации
    WateringRobot robot2("RobotA", 10.0, 5.0);

    assert(robot2.getId() == "RobotA");
    assert(robot2.getVolume() == 10.0);
    assert(robot2.getWater() == 5.0);

    //онструктора копирования
    WateringRobot robot3(robot2);

    assert(robot3.getId() == "RobotA");
    assert(robot3.getVolume() == 10.0);
    assert(robot3.getWater() == 5.0);

    //методов (насколько я знаю в C++ это называется функцией класса) доступа
    robot1.setId("RobotB");
    robot1.setVolume(15.0);
    robot1.setWater(7.5);


    assert(robot1.getId() == "RobotB");
    assert(robot1.getVolume() == 15.0);
    assert(robot1.getWater() == 7.5);

    // Тестирование методов
    robot1.fill(5.0);
    assert(robot1.getWater() == 12.5);

    robot1.pour(2.5);
    assert(robot1.getWater() == 10.0);


    std::cout << "Все тесты успешно пройдены." << std::endl;
    return 0;
}

#ifndef WATERING_ROBOT_H
#define WATERING_ROBOT_H

#include <string>

class WateringRobot {
private:
    std::string id;
    double volume;
    double water;
     
public:
    // Конструктор по умолчанию
    WateringRobot();

    // Конструктор инициализации
    WateringRobot(const std::string& id, double volume, double water);

    // Конструктор копирования
    WateringRobot(const WateringRobot& other);  

    // Методы доступа (селекторы)
    std::string getId() const;
    double getVolume() const;
    double getWater() const; 

    // Методы модификации (модификаторы)
    void setId(const std::string& id);
    void setVolume(double volume);
    void setWater(double water);

    // Методы
    void fill(double amount);
    void pour(double amount);
};

#endif

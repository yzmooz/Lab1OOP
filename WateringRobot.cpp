#include "WateringRobot.h"
#include <stdexcept>

WateringRobot::WateringRobot() // Конструктор по умолчанию
    : id(""), volume(0.0), water(0.0) {}

// Конструктор инициализации
WateringRobot::WateringRobot(const std::string& id, double volume, double water)
    : id(id), volume(volume), water(water) {
    if (volume <= 0.0) {
        throw std::invalid_argument("Объем бака должен быть положительным");
    }
    if (water < 0.0 || water > volume) {
        throw std::invalid_argument("Количество воды должно быть между 0 и объемом бака");
    }
}

// Конструктор копирования

WateringRobot::WateringRobot(const WateringRobot& other)
    : id(other.id), volume(other.volume), water(other.water) {}

// Методы доступа (селекторы)
std::string WateringRobot::getId() const {  
    return id;
}

double WateringRobot::getVolume() const {
    return volume;
}

double WateringRobot::getWater() const {
    return water;
}

//модификаторы
void WateringRobot::setId(const std::string& id) {
    this->id = id;
}

void WateringRobot::setVolume(double volume) {
    if (volume <= 0.0) {
        throw std::invalid_argument("Объем бака должен быть положительным");
    }
    if (water > volume) {
        throw std::invalid_argument("Количество воды не может превышать объем бака");
    }
    this->volume = volume;
}

void WateringRobot::setWater(double water) {
    if (water < 0.0 || water > volume) {
        throw std::invalid_argument("Количество воды должно быть между 0 и объемом бака");
    }
    this->water = water;
}


// Методы
void WateringRobot::fill(double amount) {
    if (amount <= 0.0) {
        throw std::invalid_argument("Количество для заполнения должно быть положительным");   
    }
    if (water + amount > volume) {
        throw std::overflow_error("Нельзя заполнить сверх объема бака");
    }
    water += amount;
}

void WateringRobot::pour(double amount) {
    if (amount <= 0.0) {
        throw std::invalid_argument("Количество для полива должно быть положительным");
    }  
    if (water < amount) {
        throw std::underflow_error("Недостаточно воды для полива");
    }
    water -= amount;
}




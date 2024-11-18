#ifndef CONSUMER_H
#define CONSUMER_H

#include "GameObject.h"

// A fogyasztók (anyagokat befogadók) osztálya
class Consumer : public GameObject {
public:
    Consumer(int x, int y, const std::string &color) : GameObject(x, y), color(color) {} // Konstruktor
    std::string getType() const override { return "Consumer"; }                         // Típus visszaadása
    std::string getColor() const { return color; }                                      // Szín visszaadása

private:
    std::string color; // A fogyasztó által várt anyag színe
};

#endif // CONSUMER_H

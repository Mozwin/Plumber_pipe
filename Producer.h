#ifndef PRODUCER_H
#define PRODUCER_H

#include "GameObject.h"

// A források (anyagok színének kibocsátói) osztálya
class Producer : public GameObject {
public:
    Producer(int x, int y, const std::string &color) : GameObject(x, y), color(color) {} // Konstruktor
    std::string getType() const override { return "Producer"; }                         // Típus visszaadása
    std::string getColor() const { return color; }                                      // Szín visszaadása

private:
    std::string color; // A kibocsátott anyag színe
};

#endif // PRODUCER_H

#include "Solver.h"
#include <iostream>

// Konstruktor: elmenti az objektumok listáját
Solver::Solver(const std::vector<GameObject*> &mapObjects) : mapObjects(mapObjects) {}

// A probléma megoldása
void Solver::solve() {
    for (const auto &object : mapObjects) { // Végigmegyünk az összes objektumon
        std::cout << "Solving for: " << object->getType() << std::endl;
        // TODO: A tényleges megoldási logika implementálása itt történik
        // Például: áramlás követése, csapok állapotának kezelése
    }
}

#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include "GameObject.h"

// Az osztály felelős a térképi problémák megoldásáért
class Solver {
public:
    Solver(const std::vector<GameObject*> &mapObjects); // Konstruktor: objektumok listáját fogadja
    void solve(); // Megoldja a problémát

private:
    std::vector<GameObject*> mapObjects; // Az objektumok listája (csövek, csapok stb.)
};

#endif // SOLVER_H

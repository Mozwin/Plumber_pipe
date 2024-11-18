#ifndef TAP_H
#define TAP_H

#include "GameObject.h"

// A csapok osztálya, amelyek vezérlik az anyag áramlását
class Tap : public GameObject {
public:
    Tap(int x, int y) : GameObject(x, y), isOpen(false) {}  // Konstruktor, kezdetben zárt csap
    std::string getType() const override { return "Tap"; } // Típus visszaadása

    void toggle() { isOpen = !isOpen; } // Állapot váltása nyitott és zárt között
    bool isOpenState() const { return isOpen; } // A csap aktuális állapotának lekérdezése

private:
    bool isOpen; // Nyitott vagy zárt állapot (true = nyitott, false = zárt)
};

#endif // TAP_H

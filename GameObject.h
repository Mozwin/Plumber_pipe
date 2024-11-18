#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

// Alaposztály minden térképi objektumhoz (csövek, források, fogyasztók, csapok)
// Tartalmazza az alapvető tulajdonságokat, mint a koordináták
class GameObject {
public:
    GameObject(int x, int y) : x(x), y(y) {} // Konstruktor koordinátákkal
    virtual ~GameObject() = default;        // Destruktor (polimorfikus osztályhoz szükséges)

    virtual std::string getType() const = 0; // Az objektum típusának meghatározása
    int getX() const { return x; }           // X koordináta
    int getY() const { return y; }           // Y koordináta

protected:
    int x, y; // Az objektum pozíciója a térképen
};

#endif // GAMEOBJECT_H

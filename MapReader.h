#ifndef MAPREADER_H
#define MAPREADER_H

#include <string>
#include <vector>
#include "GameObject.h"

// Az osztály felelős a térképfájl beolvasásáért és az objektumok létrehozásáért
class MapReader {
public:
    MapReader(const std::string &filePath); // Konstruktor: fájl elérési útját fogadja
    std::vector<GameObject*> parseMap();   // A fájl beolvasása és az objektumok létrehozása

private:
    std::string filePath; // A térképfájl elérési útja
};

#endif // MAPREADER_H

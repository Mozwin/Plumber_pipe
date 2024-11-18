#include "MapReader.h"
#include "Pipe.h"
#include "Producer.h"
#include "Consumer.h"
#include "Tap.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Konstruktor: elmenti a fájl elérési útját
MapReader::MapReader(const std::string &filePath) : filePath(filePath) {}

// A térképfájl beolvasása és objektumok listájának létrehozása
std::vector<GameObject*> MapReader::parseMap() {
    std::vector<GameObject*> objects; // Az objektumok listája
    std::ifstream file(filePath);    // Fájlt megnyitjuk olvasásra
    std::string line;

    while (std::getline(file, line)) { // Beolvasunk egy sort
        if (line.empty() || line[0] == '#') continue; // Üres vagy megjegyzés sorok kihagyása

        std::istringstream iss(line); // Sztringstream a sor elemzéséhez
        std::string type;
        int x, y;
        iss >> type >> x >> y; // Kiolvassuk az objektum típusát és koordinátáit

        if (type == "Pipe") { // Ha cső típusról van szó
            std::string pipeType;
            iss >> pipeType; // A cső típusának beolvasása (STRAIGHT, BEND, stb.)
            Pipe::PipeType pt = (pipeType == "STRAIGHT") ? Pipe::STRAIGHT :
                                    (pipeType == "BEND") ? Pipe::BEND :
                                    (pipeType == "CROSS") ? Pipe::CROSS : Pipe::T_SHAPE;
            objects.push_back(new Pipe(x, y, pt)); // Cső objektum létrehozása
        } else if (type == "Producer") { // Ha forrás típusról van szó
            std::string color;
            iss >> color; // A forrás színének beolvasása
            objects.push_back(new Producer(x, y, color)); // Forrás objektum létrehozása
        } else if (type == "Consumer") { // Ha fogyasztó típusról van szó
            std::string color;
            iss >> color; // A fogyasztó színének beolvasása
            objects.push_back(new Consumer(x, y, color)); // Fogyasztó objektum létrehozása
        } else if (type == "Tap") { // Ha csap típusról van szó
            objects.push_back(new Tap(x, y)); // Csap objektum létrehozása
        }
    }
    return objects; // Az összes létrehozott objektumot visszaadjuk
}

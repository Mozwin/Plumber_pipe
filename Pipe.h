#ifndef PIPE_H
#define PIPE_H

#include "GameObject.h"

// A csövek osztálya
class Pipe : public GameObject {
public:
    // A cső különböző típusai
    enum PipeType { STRAIGHT, BEND, CROSS, T_SHAPE };

    Pipe(int x, int y, PipeType type) : GameObject(x, y), type(type) {} // Konstruktor
    std::string getType() const override { return "Pipe"; }            // Típus visszaadása

    PipeType getPipeType() const { return type; } // A cső típusa

private:
    PipeType type; // A cső típusa
};

#endif // PIPE_H

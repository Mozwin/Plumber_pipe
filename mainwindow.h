#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <vector>
#include "GameObject.h"
#include "MapReader.h"
#include "Solver.h"

// Ez az osztály a főablakot kezeli, amely a program grafikus felületét biztosítja.
// Itt kezeljük a menüket, az eseményeket (fájl megnyitása, solver futtatása), és a térkép megjelenítését.
class MainWindow : public QMainWindow
{
    Q_OBJECT // Ez a makró szükséges a Qt jel-slot mechanizmusához

public:
    explicit MainWindow(QWidget *parent = nullptr); // Konstruktor: inicializálja a főablakot
    ~MainWindow();                                  // Destruktor: felszabadítja a dinamikusan foglalt memóriát

private slots:
    void openFile();        // Slot a térképfájl megnyitásához
    void runSolver();       // Slot a solver algoritmus futtatásához

private:
    QGraphicsScene *scene;  // Grafikus jelenet a térkép megjelenítéséhez
    QGraphicsView *view;    // Nézet, amely a jelenetet megjeleníti
    std::vector<GameObject*> mapObjects; // Az objektumok listája (csövek, csapok, források stb.)
    Solver *solver;         // Solver osztály példánya, amely a térképi problémát oldja meg

    void displayMap();      // Privát metódus a térkép megjelenítéséhez
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QMessageBox>

// Konstruktor: inicializálja a főablakot és a grafikus elemeket
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    scene(new QGraphicsScene(this)), // A grafikus jelenet létrehozása
    solver(nullptr)                  // A solver kezdetben nullptr
{
    this->setWindowTitle("Pipe Solver"); // Az ablak címe

    // Grafikus nézet beállítása (a scene jelenik meg benne)
    view = new QGraphicsView(scene, this);
    setCentralWidget(view); // A nézet lesz a főablak központi widgetje

    // Menü létrehozása
    QMenu *fileMenu = menuBar()->addMenu("File"); // Fájl menü
    QAction *openAction = fileMenu->addAction("Open Map"); // "Open Map" menüpont
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile); // Kapcsolás a slothoz

    QMenu *solverMenu = menuBar()->addMenu("Solver"); // Solver menü
    QAction *runAction = solverMenu->addAction("Run Solver"); // "Run Solver" menüpont
    connect(runAction, &QAction::triggered, this, &MainWindow::runSolver); // Kapcsolás a slothoz
}

// Destruktor: felszabadítja a dinamikus objektumokat
MainWindow::~MainWindow()
{
    delete scene;
    delete solver;
}

// Slot: térképfájl megnyitása
void MainWindow::openFile()
{
    // Fájlválasztó párbeszédablak
    QString fileName = QFileDialog::getOpenFileName(this, "Open Map File", "", "Text Files (*.txt)");
    if (fileName.isEmpty()) // Ha nincs fájl kiválasztva, kilép
        return;

    // MapReader használata a fájl beolvasására
    MapReader reader(fileName.toStdString());
    mapObjects = reader.parseMap(); // Az objektumokat a mapObjects listába olvassuk
    displayMap(); // Megjelenítjük a térképet
}

// Térkép megjelenítése a grafikus jelenetben
void MainWindow::displayMap()
{
    scene->clear(); // Töröljük az előző tartalmat

    for (auto *object : mapObjects) { // Bejárjuk az összes objektumot
        int x = object->getX(); // Objektum X koordinátája
        int y = object->getY(); // Objektum Y koordinátája

        // Egy 50x50-es négyzetet rajzolunk az objektum helyére
        QGraphicsRectItem *rect = scene->addRect(x * 50, y * 50, 50, 50);
        rect->setBrush(Qt::lightGray); // Szürke kitöltés

        // Az objektum típusát szövegként megjelenítjük
        QGraphicsTextItem *text = scene->addText(QString::fromStdString(object->getType()));
        text->setPos(x * 50, y * 50); // Szöveg pozíciója
    }
}

// Slot: solver algoritmus futtatása
void MainWindow::runSolver()
{
    if (mapObjects.empty()) { // Ha nincs betöltött térkép
        QMessageBox::warning(this, "Error", "No map loaded!"); // Figyelmeztetés
        return;
    }

    // Solver inicializálása és futtatása
    solver = new Solver(mapObjects);
    solver->solve(); // A térképi probléma megoldása

    displayMap(); // Frissítjük a térképet
    QMessageBox::information(this, "Solver", "Solver completed!"); // Sikeres futtatás üzenet
}

#pragma once
#ifndef GAME_H__
#define GAME_H__

#include <iostream>
#include <queue>
#include <vector>
#include <windows.h>
#include "piece.h"
#include "leftL.h"
#include "leftS.h"
#include "longBar.h"
#include "rightL.h"
#include "rightS.h"
#include "square.h"
#include "thomas.h"
#include "gameState.h"
#include "consoleDisplay.h"
#include "controller.h"
#include "gameInformation.h"

class Game
{
private:
    GameState _state;
    Piece* _currentPiece = nullptr;
    Piece* _holdPiece = nullptr;
    ColorArray2D _board = ColorArray2D(10,22);
    ConsoleDisplay _display;
    std::queue<Piece*> _queue;
    Controller* _controller = nullptr;

    int _level = 0;
    unsigned int _score = 0;
    int _totalLines = 0;
    int _totalTetris = 0;
    bool _isDirty = true;
    int _gravityspeed_milliseconds = 0;
    int _highestPiece = 0;

    int* getFullRows(int& size);
    void removeRows(int* rows, int& size);
    int countLineScore(const int& nbLine);
    Piece* getRandomPiece();
    void putPieceInBoard();
    bool gameLost();
    void updateLvlAndGravity();
    void setGravity();
    Piece* getHoldPiece();
    void addTetris();
    void updateThreat();
public:
    Game(int level);
    ~Game();

    const int extraRow = 2;

    const ColorArray2D& getBoard();
    Piece* getPiece();
    int getLevel();
    int getGravitySpeed();

    bool rotatePieceLeft();
    bool rotatePieceRight();
    bool translatePieceLeft();
    bool translatePieceRight();
    bool translatePieceDown();

    void instantDrop();
    void swapPiece();
    GameState getState();
    void start();
    void refreshUI();
    void setController(Controller* controller);
    GameInformation getGameInformation();
};

#endif // GAME_H__
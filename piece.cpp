#include "piece.h"

Piece::Piece(int width, int height){
    _array = new ColorArray2D(width, height);
    _array->fill(Color::Transparent);
    _coordinate.x = 5;
    _coordinate.y = 2;
    _width = width;
    _height = height;

}

Piece::~Piece(){
    delete  _array;
}

bool Piece::translateRight(const ColorArray2D& board)
{
    Coordinate newCoords = _coordinate;
    
    newCoords.x++;

    if(isColliding(_array, newCoords, board)){
        return false;
    }

    _coordinate = newCoords;

    return true; 
}

bool Piece::translateLeft(const ColorArray2D& board)
{
    Coordinate newCoords = _coordinate;
    
    newCoords.x--;

    if(isColliding(_array, newCoords, board)){
        return false;
    }

    _coordinate = newCoords;
    
    return true; 
}
bool Piece::translateDown(const ColorArray2D& board)
{
    Coordinate newCoords = _coordinate;

    newCoords.y++;

    if (isColliding(_array, newCoords, board)) {
        return false;
    }

    _coordinate = newCoords;

    return true;
}

bool Piece::isColliding(const ColorArray2D* future, const Coordinate pos, const ColorArray2D& board){
    
    for(int i = 0; i < future->getWidth(); i++){
        for(int j = 0; j < future->getHeight(); j++){
            if((*future)[i][j] != Color::Transparent){

                // Verify out of bound first to avoid core dumps
                if(pos.x + j < 0 || pos.x + j > board.getWidth()-1 || 
                   pos.y + i < 0 || pos.y + i > board.getHeight()-1){
                    return true;
                }

                // Verify if overlapping with element in board
                if(board[pos.y + i][pos.x + j] != Color::Transparent){
                    return true;
                }

            }
        }
    }

    return false;
}

bool Piece::rotateLeft(const ColorArray2D& board){
    
    ColorArray2D* newArray = new ColorArray2D(_array->getWidth(), _array->getHeight());

    for(int i = 0; i < _array->getWidth(); i++){
        for(int j = 0; j < _array->getHeight(); j++){
            (*newArray)[i][j] = (*_array)[_array->getWidth()-1-j][i];
        }
    }

    if(isColliding(newArray, _coordinate, board)){
        delete newArray;
        return false;
    }

    delete _array;

    _array = newArray;

    return true;
}

bool Piece::rotateRight(const ColorArray2D& board){

    ColorArray2D* newArray = new ColorArray2D(_array->getWidth(), _array->getHeight());

    for(int i = 0; i < _array->getWidth(); i++){
        for(int j = 0; j < _array->getHeight(); j++){
            (*newArray)[i][j] = (*_array)[j][_array->getWidth()-1-i];
        }
    }

    if(isColliding(newArray, _coordinate, board)){
        delete newArray;
        return false;
    }

    delete _array;

    _array = newArray;

    return true;
}

const Coordinate& Piece::getCoordinate() const
{
    return _coordinate;
}

void Piece::setCoordinate(Coordinate newCoords){
    _coordinate = newCoords;
}

ColorArray2D* Piece::getPiece() const
{
    return _array;
}

void Piece::addToColorArray2D(ColorArray2D& colorArray2D)
{
    for (int i = 0; i < _array->getHeight(); i++) {
        for (int j = 0; j < _array->getWidth(); j++) {
            if (getCoordinate().y + i < colorArray2D.getHeight() &&
                getCoordinate().y + i >= 0 &&
                getCoordinate().x + j < colorArray2D.getWidth() &&
                getCoordinate().x + j >= 0) {
                if ((*_array)[i][j] != Color::Transparent)
                {
                    colorArray2D[getCoordinate().y + i][getCoordinate().x + j] = (*_array)[i][j];
                }
            }
        }
    }
}
#include "X212.h"

// Constructeur
X212::X212(std::string nom, int direction, int force, int vitesse, int vision) :
        nom_(nom), direction_(direction), force_(force), vitesse_(vitesse), vision_(vision)
{
}

// Méthodes
int X212::bloquer() const {
    return vitesse_/3 + force_;
}

void X212::mouvement(int& x, int& y) {
    switch(direction_) {
        case 0: // Nord
            y -= vitesse_ + 1;
            break;
        case 1: // Est
            x += vitesse_ + 1;
            break;
        case 2: // Sud
            y += vitesse_ + 1;
            break;
        case 3: // Ouest
            x -= vitesse_ + 1;
            break;
        default:
            break;
    }
}

void X212::superCourse(int& x, int& y) {
    switch(direction_) {
        case 0: // Nord
            y -= vitesse_ + (vitesse_ * force_/10);
            break;
        case 1: // Est
            x += vitesse_ + (vitesse_ * force_/10);
            break;
        case 2: // Sud
            y += vitesse_ + (vitesse_ * force_/10);
            break;
        case 3: // Ouest
            x -= vitesse_ + (vitesse_ * force_/10);
            break;
        default:
            break;
    }
}

void X212::esquive(int& x, int& y, int xDanger, int yDanger) {
    int distanceX = xDanger - x;
    int distanceY = yDanger - y;
    int distanceDanger = std::sqrt(distanceX * distanceX + distanceY * distanceY);

    if (distanceDanger < 3) {
        return; // X212 ne bouge pas si le danger est trop proche
    }

    if (distanceX > distanceY) {
        if (distanceX > 0) {
            direction_ = 1; // X212 tourne à droite
        } else {
            direction_ = 3; // X212 tourne à gauche
        }
    } else {
        if (distanceY > 0) {
            direction_ = 2; // X212 tourne vers le bas
        } else {
            direction_ = 0; // X212 tourne vers le haut
        }
    }

    x += distanceX/2;
    y += distanceY/2;
}

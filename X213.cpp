#include "X213.h"

X213::X213(std::string nom, int direction, int force, int vitesse, int vision)
        : nom(nom), direction(direction), force(force), vitesse(vitesse), vision(vision) {}

int X213::bloquer() {
    return vitesse / 3 + force;
}

void X213::mouvement(int& x, int& y) {
    switch (direction) {
        case 0:
            y -= vitesse + 1;
            break;
        case 1:
            x += vitesse + 1;
            break;
        case 2:
            y += vitesse + 1;
            break;
        case 3:
            x -= vitesse + 1;
            break;
        default:
            break;
    }
}

void X213::superCourse(int& x, int& y) {
    switch (direction) {
        case 0:
            y -= vitesse + (vitesse * force / 10);
            break;
        case 1:
            x += vitesse + (vitesse * force / 10);
            break;
        case 2:
            y += vitesse + (vitesse * force / 10);
            break;
        case 3:
            x -= vitesse + (vitesse * force / 10);
            break;
        default:
            break;
    }
}

void X213::tournerLesTalons() {
    direction = (direction + 2) % 4;
}

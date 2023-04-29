#include "R234.h"

int R234::doAttack(int defenceEnemy) {
    int damage = strength - defenceEnemy;
    if (damage < 0) {
        damage = 0;
    }
    return damage;
}

int R234::doProtect(int attackEnemy) {
    int protection = attackEnemy - (speed + strength) / 2;
    if (protection < 0) {
        protection = 0;
    }
    return protection;
}

void R234::doMove(int& x, int& y) {
    switch (direction) {
        case 0: // Nord
            y -= speed;
            break;
        case 1: // Est
            x += speed;
            break;
        case 2: // Sud
            y += speed;
            break;
        case 3: // Ouest
            x -= speed;
            break;
    }
}

void R234::doRotateLeft() {
    direction = (direction + 3) % 4; // Tourner vers la gauche correspond à une rotation de 270 degrés, soit ajouter 3 à la direction et prendre le modulo 4 pour rester dans les limites de 0 à 3
}

void R234::doRotateRight() {
    direction = (direction + 1) % 4; // Tourner vers la droite correspond à une rotation de 90 degrés, soit ajouter 1 à la direction et prendre le modulo 4 pour rester dans les limites de 0 à 3
}

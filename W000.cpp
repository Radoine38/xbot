#include "W000.h"

W000::W000(string nom, int direction, int force, int vitesse, int vision) {
    this->nom = nom;
    this->direction = direction;
    this->force = force;
    this->vitesse = vitesse;
    this->vision = vision;
}

void W000::bloquer(int xAmi, int yAmi, int& x, int& y, int xEnnemi, int yEnnemi) {
    // Calcul de la distance entre l'ami et l'ennemi
    int distance = abs(xAmi - xEnnemi) + abs(yAmi - yEnnemi);

    // Si l'ennemi est à moins de la distance de mouvement de W000, il se place entre l'ami et l'ennemi
    if (distance <= vitesse) {
        // Calcul de la direction pour se placer entre l'ami et l'ennemi
        if (xAmi < xEnnemi) {
            x = xEnnemi - vitesse;
        }
        else {
            x = xEnnemi + vitesse;
        }

        if (yAmi < yEnnemi) {
            y = yEnnemi - vitesse;
        }
        else {
            y = yEnnemi + vitesse;
        }

        // Mise à jour de la direction si nécessaire
        if (x < xAmi && direction != 1) {
            direction = 1;
        }
        else if (x > xAmi && direction != 3) {
            direction = 3;
        }
        else if (y < yAmi && direction != 0) {
            direction = 0;
        }
        else if (y > yAmi && direction != 2) {
            direction = 2;
        }
    }
}

void W000::bouger(int& x, int& y) {
    // Calcul de la nouvelle position en fonction de la direction
    switch (direction) {
        case 0: // Nord
            y -= (vitesse + 2);
            break;
        case 1: // Est
            x += (vitesse + 2);
            break;
        case 2: // Sud
            y += (vitesse + 2);
            break;
        case 3: // Ouest
            x -= (vitesse + 2);
            break;
    }
}

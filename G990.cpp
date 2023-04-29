#include "G990.h"

void G990::deplacementNordSud(int valeur, int& x, int& y) {
    if (nord) {
        y -= valeur > vitesseMaximale ? vitesseMaximale : valeur;
    } else {
        y += valeur > vitesseMaximale ? vitesseMaximale : valeur;
    }
}

void G990::deplacementEstOuest(int valeur, int& x, int& y) {
    if (est) {
        x += valeur > vitesseMaximale ? vitesseMaximale : valeur;
    } else {
        x -= valeur > vitesseMaximale ? vitesseMaximale : valeur;
    }
}

void G990::regarderNord() {
    nord = true;
}

void G990::regarderSud() {
    nord = false;
}

void G990::regarderEst() {
    est = true;
}

void G990::regarderOuest() {
    est = false;
}

void G990::bloquer(int xAmi, int yAmi, int& x, int& y, int xEnnemi, int yEnnemi) {
    // Vérifie si l'ami et l'ennemi sont sur la même ligne
    if ((xAmi == xEnnemi) && (nord == (yAmi > yEnnemi))) {
        // Si l'ennemi est devant
        if ((nord && (yEnnemi > y)) || (!nord && (yEnnemi < y))) {
            // Se tourner vers l'ennemi
            nord = !nord;
        } else {
            // Se placer entre l'ami et l'ennemi
            int deplacement = std::abs(yAmi - yEnnemi) / 2;
            if (deplacement > vitesseMaximale) {
                deplacement = vitesseMaximale;
            }
            if (nord) {
                y += deplacement;
            } else {
                y -= deplacement;
            }
        }
    }
}

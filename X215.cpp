#include "X215.h"

int X215::bloquer() {
    if (rageCombat) {
        return force * 3;
    }
    else {
        return (vitesse / 3 + force);
    }
}

void X215::mouvement(int& x, int& y) {
    switch (direction) {
        case 0:
            y--;
            break;
        case 1:
            x++;
            break;
        case 2:
            y++;
            break;
        case 3:
            x--;
            break;
    }
    x = std::max(std::min(x, MAX_X), MIN_X);
    y = std::max(std::min(y, MAX_Y), MIN_Y);
}

void X215::superCourse(int& x, int& y) {
    if (rageCombat) {
        mouvement(x, y);
    }
    else {
        int deplacement = vitesse + (vitesse * force / 10);
        switch (direction) {
            case 0:
                y -= deplacement;
                break;
            case 1:
                x += deplacement;
                break;
            case 2:
                y += deplacement;
                break;
            case 3:
                x -= deplacement;
                break;
        }
        x = std::max(std::min(x, MAX_X), MIN_X);
        y = std::max(std::min(y, MAX_Y), MIN_Y);
    }
}

void X215::esquive(int& x, int& y, int xDanger, int yDanger) {
    int xDelta = x - xDanger;
    int yDelta = y - yDanger;

    if (xDelta * xDelta + yDelta * yDelta <= 9) {
        if (xDelta == 0) {
            direction = yDelta > 0 ? 0 : 2;
        }
        else if (yDelta == 0) {
            direction = xDelta > 0 ? 1 : 3;
        }
        else {
            direction = xDelta > 0 ? 1 : 3;
            direction = yDelta > 0 ? 0 : 2;
        }
        int deplacement = vitesse / 2;
        switch (direction) {
            case 0:
                y -= deplacement;
                break;
            case 1:
                x += deplacement;
                break;
            case 2:
                y += deplacement;
                break;
            case 3:
                x -= deplacement;
                break;
        }
        x = std::max(std::min(x, MAX_X), MIN_X);
        y = std::max(std::min(y, MAX_Y), MIN_Y);
    }
}

void X215::tournerLesTalons() {
    direction = (direction + 2) % 4;
}

void X215::exploserRage() {
    rageCombat = true;
}

void X215::controlerRage() {
    rageCombat = false;
}

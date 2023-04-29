#ifndef R234_H
#define R234_H

class R234 {
private:
    int direction;
    int strength;
    int speed;
    int range;

public:
    int doAttack(int defenceEnemy);
    int doProtect(int attackEnemy);
    void doMove(int& x, int& y);
    void doRotateLeft();
    void doRotateRight();
};

#endif

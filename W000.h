#ifndef W000_H
#define W000_H

#include <string>

class W000 {
private:
    std::string nom;
    int direction;
    int force;
    int vitesse;
    int vision;
public:
    W000(std::string n, int dir, int f, int vit, int vis);
    void bloquer(int xAmi, int yAmi, int& x, int& y, int xEnnemi, int yEnnemi);
    void bouger(int& x, int& y);
};

#endif // W000_H

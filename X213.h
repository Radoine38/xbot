#ifndef X213_H
#define X213_H

#include <string>

class X213 {
private:
    std::string nom;
    int direction;
    int force;
    int vitesse;
    int vision;

public:
    X213(std::string nom, int direction, int force, int vitesse, int vision);
    int bloquer();
    void mouvement(int& x, int& y);
    void superCourse(int& x, int& y);
    void tournerLesTalons();
};

#endif // X213_H

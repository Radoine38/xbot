#ifndef X212_H
#define X212_H

#include <string>

class X212 {
public:
    // Constructeur
    X212(std::string nom, int direction, int force, int vitesse, int vision);

    // Méthodes
    int bloquer() const;
    void mouvement(int& x, int& y);
    void superCourse(int& x, int& y);
    void esquive(int& x, int& y, int xDanger, int yDanger);

    // Accesseurs
    std::string getNom() const;
    int getDirection() const;
    int getForce() const;
    int getVitesse() const;
    int getVision() const;

private:
    // Attributs
    std::string nom_;
    int direction_;
    int force_;
    int vitesse_;
    int vision_;
};

// Implémentation des méthodes inline

inline std::string X212::getNom() const {
    return nom_;
}

inline int X212::getDirection() const {
    return direction_;
}

inline int X212::getForce() const {
    return force_;
}

inline int X212::getVitesse() const {
    return vitesse_;
}

inline int X212::getVision() const {
    return vision_;
}

#endif // X212_H

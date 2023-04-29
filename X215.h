#ifndef X215_H
#define X215_H

#include <string>

class X215 {
private:
    std::string nom;
    int direction;
    int force;
    int vitesse;
    int vision;
    bool rageCombat;
public:
    X215(std::string nom, int direction, int force, int vitesse, int vision);

    int bloquer() const;
    void mouvement(int& x, int& y);
    void superCourse(int& x, int& y);
    void esquive(int& x, int& y, int xDanger, int yDanger);
    void tournerLesTalons();
    void exploserRage();
    void controlerRage();

    // Getters and Setters
    std::string getNom() const { return nom; }
    void setNom(std::string nom) { this->nom = nom; }

    int getDirection() const { return direction; }
    void setDirection(int direction) { this->direction = direction; }

    int getForce() const { return force; }
    void setForce(int force) { this->force = force; }

    int getVitesse() const { return vitesse; }
    void setVitesse(int vitesse) { this->vitesse = vitesse; }

    int getVision() const { return vision; }
    void setVision(int vision) { this->vision = vision; }

    bool getRageCombat() const { return rageCombat; }
    void setRageCombat(bool rageCombat) { this->rageCombat = rageCombat; }
};

#endif // X215_H

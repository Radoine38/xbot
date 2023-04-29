#ifndef G990_H
#define G990_H

#include <iostream>
#include <string>

class G990 {
private:
    bool nord;
    bool est;
    long energiePhysique;
    long energieMaximale;
    long vision;

public:
    G990();

    void deplacementNordSud(int valeur, int& x, int& y);
    void deplacementEstOuest(int valeur, int& x, int& y);
    void regarderNord();
    void regarderSud();
    void regarderEst();
    void regarderOuest();
    void bloquer(int xAmi, int yAmi, int& x, int& y, int xEnnemi, int yEnnemi);
};
#endif

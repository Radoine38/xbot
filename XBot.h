#ifndef XBOT_H
#define XBOT_H

#include <string>

class XBot {
public:
    virtual ~XBot() = 0;
    virtual void bouger(int xAmi, int yAmi, int& x, int& y, int xEnnemi, int yEnnemi) = 0;
    virtual int attaquer(int x, int y, int xEnnemi, int yEnnemi) = 0;
    virtual void defendre(int degat) = 0;
    virtual bool estFonctionnel() const = 0;
    virtual std::string toString() const = 0;
};

#endif // XBOT_H

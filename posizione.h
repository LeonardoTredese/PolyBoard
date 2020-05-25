#ifndef POSIZIONE_H
#define POSIZIONE_H
class Posizione
{
public:
    int x, y;
    Posizione(int _x = 0, int _y = 0);
    bool operator==(const Posizione& p) const;
    bool operator!=(const Posizione& p) const;
    Posizione operator+(const Posizione& p) const;
    Posizione operator*(int value) const;
};
#endif
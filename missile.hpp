#include "elem.hpp"

#ifndef MISSILE_HPP
#define MISSILE_HPP

class missile : public elem
{
  public:
    missile(int, int, int, int);
    
    void draw() const override;
    void erase() const override;
    void updatePos(int, int) override;
 };

#endif

#include "elem.hpp"

#ifndef ALIEN_HPP
#define ALIEN_HPP

class alien : public elem
{
  public:
    alien(int, int, int, int);
    
    void draw() const override;
    void erase() const override;
    void updatePos(int, int) override;
 };

#endif

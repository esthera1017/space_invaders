#include "elem.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class player : public elem
{
  public:
    player(int, int, int, int);
    
    void draw() const override;
    void erase() const override;
    void updatePos(int, int) override;
 };

#endif

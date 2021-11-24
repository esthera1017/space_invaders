#ifndef ELEM_HPP
#define ELEM_HPP

class elem
{
  protected:
    int width;
    int length;
    int xPos;
    int yPos;
  
   public:
    elem(int, int, int, int);
    
    virtual void draw() const = 0;
    virtual void updatePos(int, int) const = 0;
   

#endif

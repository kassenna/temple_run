//
// Created by kasia on 15.05.19.
//

#include <iostream>
#include "MovingGhost.h"


MovingGhost::MovingGhost(int _x, int _y, int dX, int dY) :Sprites(_x, _y, dX, dY, 320, 1) {
    texture.loadFromFile("grafiki/ghost.png");
    sprite.setTexture(texture);
    sprite.setPosition(_x*64+16,_y*64+16);
}

void MovingGhost::move(bool _change) {

    current_time--;
    if(current_time <= 0 ){
        if (_change == false) {
            current_time = time;
            if (dx > 0)
                xp++;
            else if (dx < 0)
                xp--;
            else if (dy > 0)
                yp++;
            else if (dy < 0)
                yp--;
        }
         else{   dx*=-1;
            dy*=-1;
            current_time =1;
        }

    }
    if(current_time%5== 0)
        sprite.move(dx, dy);
}



/**
 *Copyright (c) 2018 PROPHESSOR
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#include "wl_def.h"

int automap_state;

/*
===================
=
= ToggleAutomap
=
===================
*/

void ToggleAutomap (void) {
    automap_state = !automap_state;
    UpdateAutomap();
    if(!automap_state)
        VW_UpdateScreen();
    IN_Ack();
}

void UpdateAutomap(void) {
    if(automap_state == true) {
        int x, y, z, offx, offy;

        z = 128/MAPSIZE; // zoom scale
        offx = 320/2;
        offy = (160-MAPSIZE*z)/2;

        int temp = viewsize;
        NewViewSize(16);
        DrawPlayBorder();

        uintptr_t tile;
        int color = 0;
        offx -= 64; // 128;

        for(y = 0; y < MAPSIZE; y++) {
            for(x = 0; x < 64; x++) {
                VWB_Bar(x * z + offx + 64, y * z + offy, z, z, 154);
                VWB_Bar(x * z + offx - 64, y * z + offy, z, z, 154);
            }
        }

        for(x = 0; x < MAPSIZE; x++) {
            for(y = 0; y < MAPSIZE; y++) {
                tile = (uintptr_t)actorat[x][y];
                if (ISPOINTER(tile) && ((objtype *)tile)->flags&FL_SHOOTABLE) color = 72;  // enemy
                else
                if (!tile || ISPOINTER(tile)) {
                    if (spotvis[x][y]) color = 111;  // visable
                    else color = 0;                  // nothing
                }
                else
                if (MAPSPOT(x,y,1) == PUSHABLETILE) color = 171;  // pushwall
                else
                if (tile == 64) color = 158;  // solid obj
                else
                if (tile < 128) color = 154;  // walls
                else
                if (tile < 256) color = 146;  // doors

                VWB_Bar(x*z+offx, y*z+offy,z,z,color);
            }
        }

        VWB_Bar(player->tilex*z+offx,player->tiley*z+offy,z,z,15); // player

        // resize the border to match

        VW_UpdateScreen();

        NewViewSize(temp);
        DrawPlayBorder();
    }
}
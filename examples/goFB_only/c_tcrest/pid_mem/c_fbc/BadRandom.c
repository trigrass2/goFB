// This file is generated by FBC.

#include "BadRandom.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void BadRandominit(BadRandom* me)
{
    me->_state = 0;
    me->_entered = false;
    me->_output.event.RandomChange = 0;
    me->Len = 10;
    me->Pos = 0;
    me->Vals[0] = 0.01;
    me->Vals[1] = 0.05;
    me->Vals[2] = -0.02;
    me->Vals[3] = 0.03;
    me->Vals[4] = -0.04;
    me->Vals[5] = -0.02;
    me->Vals[6] = 0.01;
    me->Vals[7] = 0.03;
    me->Vals[8] = -0.02;
    me->Vals[9] = -0.02;
}

/* ECC algorithms */
void BadRandom_BadRandomRun(BadRandom* me)
{
me->Random = me->Vals[me->Pos];

me->Pos++;

if(me->Pos >= me->Len) {
 me->Pos = 0;
}
}

/* Function block execution function */
void BadRandomrun(BadRandom* me)
{
    me->_output.event.RandomChange = 0;

	#pragma loopbound min 1 max 2
    for (;;) {
        if (me->_state == 0) {
            // State: Start
            if (!me->_entered) {
                me->_entered = true;
            }
            else {
                me->_state = 1;
                me->_entered = false;
                continue;
            }
        }
        else {
            // State: r
            if (!me->_entered) {
                BadRandom_BadRandomRun(me);
                me->_output.event.RandomChange = 1;
                me->_entered = true;
            }
            else {
                me->_state = 1;
                me->_entered = false;
                continue;
            }
        }
        break;
    }
    if (me->_output.event.RandomChange) {
        me->_Random = me->Random;
    }

}


// This file is generated by FBC.

#include "VVI_LRI.h"
#include <string.h>
#include <stdio.h>

/* Function block initialization function */
void VVI_LRIinit(VVI_LRI* me)
{
    me->_state = 0;
    me->_entered = false;
}

/* ECC algorithms */
void VVI_LRI_LRI_Set_Timeout_Value(VVI_LRI* me)
{
me -> LRI_Timeout_Value = 800;
}

/* Function block execution function */
void VVI_LRIrun(VVI_LRI* me)
{
    me->_output.event.LRI_Timer_Start = 0;
	me->_output.event.LRI_Timer_Stop = 0;
	me->_output.event.VPace = 0;

	#pragma loopbound min 1 max 2
    for (;;) {
        switch (me->_state) {
            case 0:
                // State: Start
                if (!me->_entered) {
                    me->_entered = true;
                }
                else {
                    me->_state = 1;
                    me->_entered = false;
                    continue;
                }
                break;
            case 1:
                // State: Resting
                if (!me->_entered) {
                    VVI_LRI_LRI_Set_Timeout_Value(me);
                    me->_output.event.LRI_Timer_Start = 1;
                    me->_entered = true;
                }
                else {
                    if (me->_input.event.VSense) {
                        me->_state = 2;
                        me->_entered = false;
                        continue;
                    }
                    else if (me->_input.event.LRI_Timer_Timeout) {
                        me->_state = 3;
                        me->_entered = false;
                        continue;
                    }
                }
                break;
            case 2:
                // State: VSense_Detected
                if (!me->_entered) {
                    me->_output.event.LRI_Timer_Stop = 1;
                    me->_entered = true;
                }
                else {
                    me->_state = 1;
                    me->_entered = false;
                    continue;
                }
                break;
            case 3:
                // State: LRI_Timer_Expired
                if (!me->_entered) {
                    me->_output.event.VPace = 1;
                    me->_entered = true;
                }
                else {
                    me->_state = 1;
                    me->_entered = false;
                    continue;
                }
                break;
        }
        break;
    }
    if (me->_output.event.LRI_Timer_Start) {
        me->_LRI_Timeout_Value = me->LRI_Timeout_Value;
    }

    me->_input.events = 0;
}


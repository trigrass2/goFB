// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for VVI_LRI
#include "VVI_LRI.h"


/* VVI_LRI_preinit() is required to be called to 
 * initialise an instance of VVI_LRI. 
 * It sets all I/O values to zero.
 */
int VVI_LRI_preinit(VVI_LRI_t  *me) {
	//if there are input events, reset them
	me->inputEvents.event.VSense = 0;
	me->inputEvents.event.LRI_Timer_Timeout = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.LRI_Timer_Start = 0;
	me->outputEvents.event.LRI_Timer_Stop = 0;
	me->outputEvents.event.VPace = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_VVI_LRI_Start;
	

	return 0;
}

/* VVI_LRI_init() is required to be called to 
 * set up an instance of VVI_LRI. 
 * It passes around configuration data.
 */
int VVI_LRI_init(VVI_LRI_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



//algorithms

void VVI_LRI_LRI_Set_Timeout_Value(VVI_LRI_t  *me) {
me -> LRI_Timeout_Value = 800;
}



/* VVI_LRI_run() executes a single tick of an
 * instance of VVI_LRI according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void VVI_LRI_run(VVI_LRI_t  *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.LRI_Timer_Start = 0;
	me->outputEvents.event.LRI_Timer_Stop = 0;
	me->outputEvents.event.VPace = 0;
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_VVI_LRI_Start:
			if(true) {
				me->_state = STATE_VVI_LRI_Resting;
				me->_trigger = true;
				
			};
			break;
		case STATE_VVI_LRI_Resting:
			if(me->inputEvents.event.VSense) {
				me->_state = STATE_VVI_LRI_VSense_Detected;
				me->_trigger = true;
				
			} else if(me->inputEvents.event.LRI_Timer_Timeout) {
				me->_state = STATE_VVI_LRI_LRI_Timer_Expired;
				me->_trigger = true;
				
			};
			break;
		case STATE_VVI_LRI_LRI_Timer_Expired:
			if(true) {
				me->_state = STATE_VVI_LRI_Resting;
				me->_trigger = true;
				
			};
			break;
		case STATE_VVI_LRI_VSense_Detected:
			if(true) {
				me->_state = STATE_VVI_LRI_Resting;
				me->_trigger = true;
				
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_VVI_LRI_Start:
			break;

		case STATE_VVI_LRI_Resting:
			VVI_LRI_LRI_Set_Timeout_Value(me);
			me->outputEvents.event.LRI_Timer_Start = 1;
			break;

		case STATE_VVI_LRI_LRI_Timer_Expired:
			me->outputEvents.event.VPace = 1;
			break;

		case STATE_VVI_LRI_VSense_Detected:
			me->outputEvents.event.LRI_Timer_Stop = 1;
			break;

		
		}
	}

	me->_trigger = false;
}



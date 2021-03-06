// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for Pass
#include "Pass.h"


/* Pass_preinit() is required to be called to 
 * initialise an instance of Pass. 
 * It sets all I/O values to zero.
 */
int Pass_preinit(Pass_t _SPM *me) {
	//if there are input events, reset them
	me->inputEvents.event.CountChanged = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.OutCountChanged = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_Pass_Start;
	

	return 0;
}

/* Pass_init() is required to be called to 
 * set up an instance of Pass. 
 * It passes around configuration data.
 */
int Pass_init(Pass_t _SPM *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



//algorithms

void Pass_UpdateCountOut(Pass_t _SPM *me) {
me->OutCount = me->Count;
}



/* Pass_run() executes a single tick of an
 * instance of Pass according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void Pass_run(Pass_t _SPM *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.OutCountChanged = 0;
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_Pass_Start:
			if(me->inputEvents.event.CountChanged) {
				me->_state = STATE_Pass_update;
				me->_trigger = true;
				
			};
			break;
		case STATE_Pass_update:
			if(me->inputEvents.event.CountChanged) {
				me->_state = STATE_Pass_update;
				me->_trigger = true;
				
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_Pass_Start:
			break;

		case STATE_Pass_update:
			Pass_UpdateCountOut(me);
			me->outputEvents.event.OutCountChanged = 1;
			break;

		
		}
	}

	me->_trigger = false;
}



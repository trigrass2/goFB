// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for interResourceRxBool
#include "interResourceRxBool.h"


/* interResourceRxBool_preinit() is required to be called to 
 * initialise an instance of interResourceRxBool. 
 * It sets all I/O values to zero.
 */
int interResourceRxBool_preinit(interResourceRxBool_t  *me) {
	//if there are input events, reset them
	
	//if there are output events, reset them
	me->outputEvents.event.Rx = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB/odeFB, set start state so that the start state is properly executed and _trigger if necessary
	me->_state = STATE_interResourceRxBool_Start;
	me->_trigger = true;
	
	
	
	
	return 0;
}

/* interResourceRxBool_init() is required to be called to 
 * set up an instance of interResourceRxBool. 
 * It passes around configuration data.
 */
int interResourceRxBool_init(interResourceRxBool_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



//algorithms

void interResourceRxBool_gen(interResourceRxBool_t  *me) {
	static int tickCount = 0;
//PROVIDED CODE: this algorithm was provided in an algorithm's text field
// if(something) {
// 	something;
// 	something;
// 	me->outputEvents.Rx = 1;
// }

if(tickCount == 0) {
	me->Data = !me->Data;
}
tickCount++;
if(tickCount == 50) {
	tickCount = 0;
}
me->outputEvents.event.Rx = 1;
}



/* interResourceRxBool_run() executes a single tick of an
 * instance of interResourceRxBool according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void interResourceRxBool_run(interResourceRxBool_t  *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.Rx = 0;
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_interResourceRxBool_Start:
			if(true) {
				me->_state = STATE_interResourceRxBool_update;
				me->_trigger = true;
			};
			break;
		case STATE_interResourceRxBool_update:
			if(true) {
				me->_state = STATE_interResourceRxBool_update;
				me->_trigger = true;
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_interResourceRxBool_Start:
			break;

		case STATE_interResourceRxBool_update:
			interResourceRxBool_gen(me);
			break;

		
		}
	}

	me->_trigger = false;
}


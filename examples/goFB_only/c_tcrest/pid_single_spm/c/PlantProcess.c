// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for PlantProcess
#include "PlantProcess.h"


/* PlantProcess_preinit() is required to be called to 
 * initialise an instance of PlantProcess. 
 * It sets all I/O values to zero.
 */
int PlantProcess_preinit(PlantProcess_t _SPM *me) {
	//if there are input events, reset them
	me->inputEvents.event.Zero = 0;
	me->inputEvents.event.ControlChange = 0;
	me->inputEvents.event.RandomChange = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.ValueChange = 0;
	
	//if there are input vars with default values, set them
	me->Random = 0.0;
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_PlantProcess_Start;
	

	return 0;
}

/* PlantProcess_init() is required to be called to 
 * set up an instance of PlantProcess. 
 * It passes around configuration data.
 */
int PlantProcess_init(PlantProcess_t _SPM *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



//algorithms

void PlantProcess_PlantZero(PlantProcess_t _SPM *me) {
me->Value = 0;
}

void PlantProcess_PlantTick(PlantProcess_t _SPM *me) {
me->Value += me->Control + me->Random;
}



/* PlantProcess_run() executes a single tick of an
 * instance of PlantProcess according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void PlantProcess_run(PlantProcess_t _SPM *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.ValueChange = 0;
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_PlantProcess_Start:
			if(true) {
				me->_state = STATE_PlantProcess_zero;
				me->_trigger = true;
				
			};
			break;
		case STATE_PlantProcess_zero:
			if(true) {
				me->_state = STATE_PlantProcess_tick;
				me->_trigger = true;
				
			};
			break;
		case STATE_PlantProcess_tick:
			if(me->inputEvents.event.Zero) {
				me->_state = STATE_PlantProcess_zero;
				me->_trigger = true;
				
			} else if(true) {
				me->_state = STATE_PlantProcess_tick;
				me->_trigger = true;
				
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_PlantProcess_Start:
			break;

		case STATE_PlantProcess_zero:
			PlantProcess_PlantZero(me);
			break;

		case STATE_PlantProcess_tick:
			PlantProcess_PlantTick(me);
			me->outputEvents.event.ValueChange = 1;
			break;

		
		}
	}

	me->_trigger = false;
}


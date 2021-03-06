// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for PID
#include "PID.h"


/* PID_preinit() is required to be called to 
 * initialise an instance of PID. 
 * It sets all I/O values to zero.
 */
int PID_preinit(PID_t  *me) {
	//if there are input events, reset them
	me->inputEvents.event.Zero = 0;
	me->inputEvents.event.Tick = 0;
	me->inputEvents.event.ActualValueChanged = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.ControlChanged = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_PID_Start;
	

	return 0;
}

/* PID_init() is required to be called to 
 * set up an instance of PID. 
 * It passes around configuration data.
 */
int PID_init(PID_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}



//algorithms

void PID_PIDTick(PID_t  *me) {
	REAL diff;
	REAL p_term;
	REAL i_term;
	REAL d_term;

	REAL currentError = me->DesiredValue - me->ActualValue;
 
    // integration with windup guarding
    me->IntegrationError += currentError;
    if (me->IntegrationError < -(me->WindupGuard)) {
        me->IntegrationError = -(me->WindupGuard);

	} else if (me->IntegrationError > me->WindupGuard) {
        me->IntegrationError = me->WindupGuard;

	}

    // differentiation
    diff = currentError - me->PreviousError;
 
    // scaling
    p_term = (me->PGain * currentError);
    i_term = (me->IGain * me->IntegrationError);
    d_term = (me->DGain * diff);
 
    // summation of terms
    me->Control = p_term + i_term + d_term;
 
    // save current error as previous error for next iteration
    me->PreviousError = currentError;
}

void PID_PIDZero(PID_t  *me) {
me->PreviousError = 0.0;
me->IntegrationError = 0.0;
}



/* PID_run() executes a single tick of an
 * instance of PID according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void PID_run(PID_t  *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.ControlChanged = 0;
	

	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_PID_Start:
			if(true) {
				me->_state = STATE_PID_zero;
				me->_trigger = true;
				
			};
			break;
		case STATE_PID_update:
			if(me->inputEvents.event.Zero) {
				me->_state = STATE_PID_zero;
				me->_trigger = true;
				
			} else if(me->inputEvents.event.Tick) {
				me->_state = STATE_PID_update;
				me->_trigger = true;
				
			};
			break;
		case STATE_PID_zero:
			if(me->inputEvents.event.Tick) {
				me->_state = STATE_PID_update;
				me->_trigger = true;
				
			} else if(me->inputEvents.event.Zero) {
				me->_state = STATE_PID_zero;
				me->_trigger = true;
				
			};
			break;
		
		}
	}

	//state output logic
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_PID_Start:
			break;

		case STATE_PID_update:
			PID_PIDTick(me);
			me->outputEvents.event.ControlChanged = 1;
			break;

		case STATE_PID_zero:
			PID_PIDZero(me);
			break;

		
		}
	}

	me->_trigger = false;
}



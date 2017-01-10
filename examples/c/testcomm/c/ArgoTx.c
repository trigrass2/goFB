// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Basic Function Block for ArgoTx
#include "ArgoTx.h"


/* ArgoTx_init() is required to be called to 
 * initialise an instance of ArgoTx. 
 * It sets all I/O values to zero.
 */
int ArgoTx_init(struct ArgoTx *me) {
	//if there are input events, reset them
	me->inputEvents.events[0] = 0;
	
	//if there are output events, reset them
	me->outputEvents.events[0] = 0;
	
	//if there are input vars with default values, set them
	me->ChanId = 1;
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//perform a data copy to all children (if any present) (moves config data around)
	//TODO:

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	me->_trigger = true;
	me->_state = STATE_ArgoTx_Start;
	
	me->chan = mp_create_qport(1, SOURCE, sizeof(INT), 1);
	me->write_data = mp_alloc(sizeof(INT));
	if(me->chan == NULL || me->write_data == NULL) {
		return 1;
	}

	return 0;
}



/* ArgoTx_run() executes a single tick of an
 * instance of ArgoTx according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void ArgoTx_run(struct ArgoTx *me) {
	//if there are output events, reset them
	me->outputEvents.events[0] = 0;

	if(me->inputEvents.event.DataPresent) {
		*((volatile INT _SPM *)me->chan->write_buf) = me->Data;
		me->Success = mp_nbsend(me->chan);
		me->outputEvents.event.SuccessChanged = 1;
	}
}

//no algorithms were present for this function block



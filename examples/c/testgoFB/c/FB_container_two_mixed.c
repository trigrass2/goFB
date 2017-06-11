// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Composite Function Block for container_two_mixed
#include "FB_container_two_mixed.h"

//When running a composite block, note that you would call the functions in this order (and this is very important)
//_preinit(); 
//_init();
//do {
//	_syncOutputEvents();
//	_syncInputEvents();
//	_syncOutputData();
//	_syncInputData();
//	_run();
//} loop;


/* container_two_mixed_preinit() is required to be called to 
 * initialise an instance of container_two_mixed. 
 * It sets all I/O values to zero.
 */
int container_two_mixed_preinit(container_two_mixed_t  *me) {
	//if there are input events, reset them
	me->inputEvents.event.DataInChanged = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.DataOutChanged = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(container_one_preinit(&me->cf1) != 0) {
		return 1;
	}
	if(passforward_preinit(&me->pf2) != 0) {
		return 1;
	}
	
	

	

	//if this is a BFB/odeFB, set start state so that the start state is properly executed and _trigger if necessary
	

	return 0;
}

/* container_two_mixed_init() is required to be called to 
 * set up an instance of container_two_mixed. 
 * It passes around configuration data.
 */
int container_two_mixed_init(container_two_mixed_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	
	//sync config for cf1 (of Type container_one) 
	
	
		me->cf1.DataIn = me->DataIn;
	
	
		me->cf1.printf_id = me->printf_id1;
	//sync config for pf2 (of Type passforward) 
	
	
		me->pf2.DataIn = me->cf1.DataOut;
	
	
		me->pf2.printf_id = me->printf_id2;
	

	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(container_one_init(&me->cf1) != 0) {
		return 1;
	}
	if(passforward_init(&me->pf2) != 0) {
		return 1;
	}
	
	

	return 0;
}



/* container_two_mixed_syncOutputEvents() synchronises the output events of an
 * instance of container_two_mixed as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void container_two_mixed_syncOutputEvents(container_two_mixed_t  *me) {
	//first, for all cfb children, call this same function
	
	container_one_syncOutputEvents(&me->cf1);//sync for cf1 (of type container_one) which is a CFB
	
	
	//then, for all connections that are connected to an output on the parent, run their run their copy
	
	me->outputEvents.event.DataOutChanged = me->pf2.outputEvents.event.DataOutChanged; 
	
}

/* container_two_mixed_syncInputEvents() synchronises the input events of an
 * instance of container_two_mixed as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void container_two_mixed_syncInputEvents(container_two_mixed_t  *me) {
	//first, we explicitly synchronise the children
	
	me->cf1.inputEvents.event.DataInChanged = me->inputEvents.event.DataInChanged; 
	
	me->pf2.inputEvents.event.DataInChanged = me->cf1.outputEvents.event.DataOutChanged; 
	

	//then, call this same function on all cfb children
	
	container_one_syncInputEvents(&me->cf1);//sync for cf1 (of type container_one) which is a CFB
	
}

/* container_two_mixed_syncOutputData() synchronises the output data connections of an
 * instance of container_two_mixed as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void container_two_mixed_syncOutputData(container_two_mixed_t  *me) {
	//for all composite function block children, call this same function
	//sync for cf1 (of type container_one) which is a CFB
	container_one_syncOutputData(&me->cf1);
	
	//for data that is sent from child to this CFB (me), always copy (event controlled copies will be resolved at the next level up) //TODO: arrays!?
	me->DataOut = me->pf2.DataOut;
	
	
}

/* container_two_mixed_syncInputData() synchronises the input data connections of an
 * instance of container_two_mixed as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void container_two_mixed_syncInputData(container_two_mixed_t  *me) {
	//for all basic function block children, perform their synchronisations explicitly
	//sync for cf1 (of Type container_one) which is a CFB
	
	
		me->cf1.DataIn = me->DataIn;
	
	
		me->cf1.printf_id = me->printf_id1;
	
	//sync for pf2 (of type passforward) which is a BFB
	
	if(me->pf2.inputEvents.event.DataInChanged == 1) { 
		me->pf2.DataIn = me->cf1.DataOut;
	} 
	
	
	//for all composite function block children, call this same function
	//sync for cf1 (of type container_one) which is a CFB
	container_one_syncInputData(&me->cf1);
	
}


/* container_two_mixed_run() executes a single tick of an
 * instance of container_two_mixed according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void container_two_mixed_run(container_two_mixed_t  *me) {
	container_one_run(&me->cf1);
	passforward_run(&me->pf2);
	
}


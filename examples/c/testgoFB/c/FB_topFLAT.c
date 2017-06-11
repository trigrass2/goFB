// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Composite Function Block for topFLAT
#include "FB_topFLAT.h"

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


/* topFLAT_preinit() is required to be called to 
 * initialise an instance of topFLAT. 
 * It sets all I/O values to zero.
 */
int topFLAT_preinit(topFLAT_t  *me) {
	//if there are input events, reset them
	
	//if there are output events, reset them
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(passforward_preinit(&me->pf1) != 0) {
		return 1;
	}
	if(passforward_preinit(&me->pf2) != 0) {
		return 1;
	}
	if(passforward_preinit(&me->pf3) != 0) {
		return 1;
	}
	if(passforward_preinit(&me->pf4) != 0) {
		return 1;
	}
	
	

	

	//if this is a BFB/odeFB, set start state so that the start state is properly executed and _trigger if necessary
	

	return 0;
}

/* topFLAT_init() is required to be called to 
 * set up an instance of topFLAT. 
 * It passes around configuration data.
 */
int topFLAT_init(topFLAT_t  *me) {
	//pass in any parameters on this level
	me->pf1.printf_id = 1;
	me->pf2.printf_id = 2;
	me->pf3.printf_id = 3;
	me->pf4.printf_id = 4;
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	
	//sync config for pf1 (of Type passforward) 
	
	
		me->pf1.DataIn = me->pf4.DataOut;
	
	//sync config for pf2 (of Type passforward) 
	
	
		me->pf2.DataIn = me->pf1.DataOut;
	
	//sync config for pf3 (of Type passforward) 
	
	
		me->pf3.DataIn = me->pf2.DataOut;
	
	//sync config for pf4 (of Type passforward) 
	
	
		me->pf4.DataIn = me->pf3.DataOut;
	
	

	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(passforward_init(&me->pf1) != 0) {
		return 1;
	}
	if(passforward_init(&me->pf2) != 0) {
		return 1;
	}
	if(passforward_init(&me->pf3) != 0) {
		return 1;
	}
	if(passforward_init(&me->pf4) != 0) {
		return 1;
	}
	
	

	return 0;
}



/* topFLAT_syncOutputEvents() synchronises the output events of an
 * instance of topFLAT as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void topFLAT_syncOutputEvents(topFLAT_t  *me) {
	//first, for all cfb children, call this same function
	
	
	//then, for all connections that are connected to an output on the parent, run their run their copy
	
}

/* topFLAT_syncInputEvents() synchronises the input events of an
 * instance of topFLAT as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void topFLAT_syncInputEvents(topFLAT_t  *me) {
	//first, we explicitly synchronise the children
	
	me->pf1.inputEvents.event.DataInChanged = me->pf4.outputEvents.event.DataOutChanged; 
	
	me->pf2.inputEvents.event.DataInChanged = me->pf1.outputEvents.event.DataOutChanged; 
	
	me->pf3.inputEvents.event.DataInChanged = me->pf2.outputEvents.event.DataOutChanged; 
	
	me->pf4.inputEvents.event.DataInChanged = me->pf3.outputEvents.event.DataOutChanged; 
	

	//then, call this same function on all cfb children
	
}

/* topFLAT_syncOutputData() synchronises the output data connections of an
 * instance of topFLAT as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void topFLAT_syncOutputData(topFLAT_t  *me) {
	//for all composite function block children, call this same function
	
	
	//for data that is sent from child to this CFB (me), always copy (event controlled copies will be resolved at the next level up) //TODO: arrays!?
	
	
}

/* topFLAT_syncInputData() synchronises the input data connections of an
 * instance of topFLAT as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void topFLAT_syncInputData(topFLAT_t  *me) {
	//for all basic function block children, perform their synchronisations explicitly
	
	//sync for pf1 (of type passforward) which is a BFB
	
	if(me->pf1.inputEvents.event.DataInChanged == 1) { 
		me->pf1.DataIn = me->pf4.DataOut;
	} 
	
	//sync for pf2 (of type passforward) which is a BFB
	
	if(me->pf2.inputEvents.event.DataInChanged == 1) { 
		me->pf2.DataIn = me->pf1.DataOut;
	} 
	
	//sync for pf3 (of type passforward) which is a BFB
	
	if(me->pf3.inputEvents.event.DataInChanged == 1) { 
		me->pf3.DataIn = me->pf2.DataOut;
	} 
	
	//sync for pf4 (of type passforward) which is a BFB
	
	if(me->pf4.inputEvents.event.DataInChanged == 1) { 
		me->pf4.DataIn = me->pf3.DataOut;
	} 
	
	
	//for all composite function block children, call this same function
	
	
}


/* topFLAT_run() executes a single tick of an
 * instance of topFLAT according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void topFLAT_run(topFLAT_t  *me) {
	passforward_run(&me->pf1);
	passforward_run(&me->pf2);
	passforward_run(&me->pf3);
	passforward_run(&me->pf4);
	
}


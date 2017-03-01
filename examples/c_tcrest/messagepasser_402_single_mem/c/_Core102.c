// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the Composite Function Block for _Core102
#include "_Core102.h"

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


/* _Core102_preinit() is required to be called to 
 * initialise an instance of _Core102. 
 * It sets all I/O values to zero.
 */
int _Core102_preinit(_Core102_t  *me) {
	//if there are input events, reset them
	
	//if there are output events, reset them
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(Gen_preinit(&me->gen) != 0) {
		return 1;
	}
	if(Print_preinit(&me->print) != 0) {
		return 1;
	}
	if(Pass50_preinit(&me->p50_1) != 0) {
		return 1;
	}
	if(Pass50_preinit(&me->p50_2) != 0) {
		return 1;
	}
	
	
	//if this is a BFB, set _trigger to be true and start state so that the start state is properly executed
	

	return 0;
}

/* _Core102_init() is required to be called to 
 * set up an instance of _Core102. 
 * It passes around configuration data.
 */
int _Core102_init(_Core102_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	me->p50_1.Count = me->gen.Count;
	me->p50_2.Count = me->p50_1.OutCount;
	me->print.Count = me->p50_2.OutCount;
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	if(Gen_init(&me->gen) != 0) {
		return 1;
	}
	if(Print_init(&me->print) != 0) {
		return 1;
	}
	if(Pass50_init(&me->p50_1) != 0) {
		return 1;
	}
	if(Pass50_init(&me->p50_2) != 0) {
		return 1;
	}
	
	

	return 0;
}



/* _Core102_syncOutputEvents() synchronises the output events of an
 * instance of _Core102 as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _Core102_syncOutputEvents(_Core102_t  *me) {
	//first, for all cfb children, call this same function
	
	Pass50_syncOutputEvents(&me->p50_1);//sync for p50_1 (of type Pass50) which is a CFB
	
	Pass50_syncOutputEvents(&me->p50_2);//sync for p50_2 (of type Pass50) which is a CFB
	
	
	//then, for all connections that are connected to an output on the parent, run their run their copy
	
}

/* _Core102_syncInputEvents() synchronises the input events of an
 * instance of _Core102 as required by synchronous semantics.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _Core102_syncInputEvents(_Core102_t  *me) {
	//first, we explicitly synchronise the children
	
	me->print.inputEvents.event.CountChanged = me->p50_2.outputEvents.event.OutCountChanged; 
	
	me->p50_1.inputEvents.event.CountChanged = me->gen.outputEvents.event.CountChanged; 
	
	me->p50_2.inputEvents.event.CountChanged = me->p50_1.outputEvents.event.OutCountChanged; 
	

	//then, call this same function on all cfb children
	
	Pass50_syncInputEvents(&me->p50_1);//sync for p50_1 (of type Pass50) which is a CFB
	
	Pass50_syncInputEvents(&me->p50_2);//sync for p50_2 (of type Pass50) which is a CFB
	
}

/* _Core102_syncOutputData() synchronises the output data connections of an
 * instance of _Core102 as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _Core102_syncOutputData(_Core102_t  *me) {
	//for all composite function block children, call this same function
	//sync for p50_1 (of type Pass50) which is a CFB
	Pass50_syncOutputData(&me->p50_1);//sync for p50_2 (of type Pass50) which is a CFB
	Pass50_syncOutputData(&me->p50_2);
	
	//for data that is sent from child to this CFB (me), always copy (event controlled copies will be resolved at the next level up) //TODO: arrays!?
	
	
}

/* _Core102_syncInputData() synchronises the input data connections of an
 * instance of _Core102 as required by synchronous semantics.
 * It does the checking to ensure that only connections which have had their
 * associated event fire are updated.
 * Notice that it does NOT perform any computation - this occurs in the
 * _run function.
 */
void _Core102_syncInputData(_Core102_t  *me) {
	//for all basic function block children, perform their synchronisations explicitly
	
	//sync for gen (of type Gen) which is a BFB
	
	
	//sync for print (of type Print) which is a BFB
	
	if(me->print.inputEvents.event.CountChanged == 1) { 
		me->print.Count = me->p50_2.OutCount;
	} 
	//sync for p50_1 (of Type Pass50) which is a CFB
	
	
		me->p50_1.Count = me->gen.Count;
	//sync for p50_2 (of Type Pass50) which is a CFB
	
	
		me->p50_2.Count = me->p50_1.OutCount;
	
	
	//for all composite function block children, call this same function
	//sync for p50_1 (of type Pass50) which is a CFB
	Pass50_syncInputData(&me->p50_1);//sync for p50_2 (of type Pass50) which is a CFB
	Pass50_syncInputData(&me->p50_2);
	
}


/* _Core102_run() executes a single tick of an
 * instance of _Core102 according to synchronise semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * is done using the _syncX functions at this (and any higher) level.
 */
void _Core102_run(_Core102_t  *me) {
	Gen_run(&me->gen);
	Print_run(&me->print);
	Pass50_run(&me->p50_1);
	Pass50_run(&me->p50_2);
	
}


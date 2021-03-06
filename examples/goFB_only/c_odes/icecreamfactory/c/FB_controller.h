// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block controller
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "fbtypes.h"
#include "util.h"



//This is a BFB, so we need an enum type for the state machine
enum controller_states { STATE_controller_Start, STATE_controller_State1, STATE_controller_State2 };


union controllerInputEvents {
	struct {
		UDINT update;
	} event;
	
};


union controllerOutputEvents {
	struct {
		UDINT S2;
		UDINT S3;
	} event;
	
};


typedef struct {
    //input events
	union controllerInputEvents inputEvents;

    //output events
	union controllerOutputEvents outputEvents;

    //input vars
	LREAL x;
    LREAL y;
    
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum controller_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	

	
} controller_t;

//all FBs get a preinit function
int controller_preinit(controller_t  *me);

//all FBs get an init function
int controller_init(controller_t  *me);

//all FBs get a run function
void controller_run(controller_t  *me);



#endif

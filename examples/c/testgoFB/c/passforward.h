// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block passforward
#ifndef PASSFORWARD_H_
#define PASSFORWARD_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum passforward_states { STATE_passforward_Start, STATE_passforward_emit_data, STATE_passforward_count };


union passforwardInputEvents {
	struct {
		UDINT DataInChanged;
	} event;
	
};


union passforwardOutputEvents {
	struct {
		UDINT DataOutChanged;
	} event;
	
};


typedef struct {
    //input events
	union passforwardInputEvents inputEvents;

    //output events
	union passforwardOutputEvents outputEvents;

    //input vars
	INT DataIn;
    INT printf_id;
    
    //output vars
	INT DataOut;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum passforward_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
} passforward_t;

//all FBs get a preinit function
int passforward_preinit(passforward_t  *me);

//all FBs get an init function
int passforward_init(passforward_t  *me);

//all FBs get a run function
void passforward_run(passforward_t  *me);



#endif

// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block PrintString
#ifndef PRINTSTRING_H_
#define PRINTSTRING_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum PrintString_states { STATE_PrintString_Start, STATE_PrintString_Await_data };


union PrintStringInputEvents {
	struct {
		UDINT DataPresent;
	} event;
	
};


//this block had no output events


typedef struct {
    //input events
	union PrintStringInputEvents inputEvents;

    //output events
	

    //input vars
	STRING Data;
    
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum PrintString_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
} PrintString_t;

//all FBs get a preinit function
int PrintString_preinit(PrintString_t _SPM *me);

//all FBs get an init function
int PrintString_init(PrintString_t _SPM *me);

//all FBs get a run function
void PrintString_run(PrintString_t _SPM *me);

//basic FBs have a number of algorithm functions

void PrintString_DoPrintString(PrintString_t _SPM *me);


#endif

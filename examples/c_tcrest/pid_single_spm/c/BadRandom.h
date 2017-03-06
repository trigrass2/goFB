// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block BadRandom
#ifndef BADRANDOM_H_
#define BADRANDOM_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum BadRandom_states { STATE_BadRandom_Start, STATE_BadRandom_r };


//this block had no input events


union BadRandomOutputEvents {
	struct {
		UDINT RandomChange;
	} event;
	
};


typedef struct {
    //input events
	

    //output events
	union BadRandomOutputEvents outputEvents;

    //input vars
	
    //output vars
	REAL Random;
    
	//any internal vars (BFBs only)
    INT Len;
    INT Pos;
    REAL Vals[10];
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum BadRandom_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
} BadRandom_t;

//all FBs get a preinit function
int BadRandom_preinit(BadRandom_t _SPM *me);

//all FBs get an init function
int BadRandom_init(BadRandom_t _SPM *me);

//all FBs get a run function
void BadRandom_run(BadRandom_t _SPM *me);



#endif

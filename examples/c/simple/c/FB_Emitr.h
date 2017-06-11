// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block Emitr
#ifndef EMITR_H_
#define EMITR_H_

#include "fbtypes.h"
#include "util.h"



//This is a BFB, so we need an enum type for the state machine
enum Emitr_states { STATE_Emitr_start };


//this block had no input events


union EmitrOutputEvents {
	struct {
		UDINT e;
	} event;
	
};


typedef struct {
    //input events
	

    //output events
	union EmitrOutputEvents outputEvents;

    //input vars
	
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum Emitr_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	

	
} Emitr_t;

//all FBs get a preinit function
int Emitr_preinit(Emitr_t  *me);

//all FBs get an init function
int Emitr_init(Emitr_t  *me);

//all FBs get a run function
void Emitr_run(Emitr_t  *me);



#endif
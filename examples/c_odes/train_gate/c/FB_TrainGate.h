// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block TrainGate
#ifndef TRAINGATE_H_
#define TRAINGATE_H_

#include "fbtypes.h"
#include "util.h"



//This is a CFB, so we need the #includes for the child blocks embedded here
#include "FB_Plant.h"
#include "FB_Controller.h"


//this block had no input events


//this block had no output events


typedef struct {
    //input events
	

    //output events
	

    //input vars
	
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	Plant_t p;
	Controller_t c;
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	
} TrainGate_t;

//all FBs get a preinit function
int TrainGate_preinit(TrainGate_t  *me);

//all FBs get an init function
int TrainGate_init(TrainGate_t  *me);

//all FBs get a run function
void TrainGate_run(TrainGate_t  *me);

//composite/resource/device FBs get sync functions
void TrainGate_syncOutputEvents(TrainGate_t  *me);
void TrainGate_syncInputEvents(TrainGate_t  *me);

void TrainGate_syncOutputData(TrainGate_t  *me);
void TrainGate_syncInputData(TrainGate_t  *me);



#endif
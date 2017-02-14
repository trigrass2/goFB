// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block topFLAT
#ifndef TOPFLAT_H_
#define TOPFLAT_H_

#include "fbtypes.h"

//This is a CFB, so we need the #includes for the child blocks embedded here
#include "passforward.h"
#include "passforward.h"
#include "passforward.h"
#include "passforward.h"


//this block had no input events


//this block had no output events


typedef struct {
    //input events
	

    //output events
	

    //input vars
	
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	passforward_t pf1;
	passforward_t pf2;
	passforward_t pf3;
	passforward_t pf4;
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	
} topFLAT_t;

//all FBs get a preinit function
int topFLAT_preinit(topFLAT_t  *me);

//all FBs get an init function
int topFLAT_init(topFLAT_t  *me);

//all FBs get a run function
void topFLAT_run(topFLAT_t  *me);

//composite/resource/device FBs get sync functions
void topFLAT_syncOutputEvents(topFLAT_t  *me);
void topFLAT_syncInputEvents(topFLAT_t  *me);

void topFLAT_syncOutputData(topFLAT_t  *me);
void topFLAT_syncInputData(topFLAT_t  *me);



#endif

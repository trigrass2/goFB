// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block _Core0
#ifndef _CORE0_H_
#define _CORE0_H_

#include "fbtypes.h"

//This is a CFB, so we need the #includes for the child blocks embedded here
#include "ArgoRx.h"
#include "ArgoRx.h"
#include "ArgoRx.h"
#include "PrintStatus.h"


//this block had no input events


//this block had no output events


struct _Core0 {
    //input events
	

    //output events
	

    //input vars
	
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	struct ArgoRx saw1rx;
	struct ArgoRx saw2rx;
	struct ArgoRx saw3rx;
	struct PrintStatus statusprint;
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	
};

//all FBs get a preinit function
int _Core0_preinit(struct _Core0 *me);

//all FBs get an init function
int _Core0_init(struct _Core0 *me);

//all FBs get a run function
void _Core0_run(struct _Core0 _SPM *me);

//composite/resource/device FBs get sync functions
void _Core0_syncEvents(struct _Core0 _SPM *me);
void _Core0_syncData(struct _Core0 _SPM *me);

#endif

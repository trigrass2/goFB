// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block _WaterHeaterController
#ifndef _WATERHEATERCONTROLLER_H_
#define _WATERHEATERCONTROLLER_H_

#include "fbtypes.h"



//This is a CFB, so we need the #includes for the child blocks embedded here


//this block had no input events


//this block had no output events


typedef struct {
    //input events
	

    //output events
	

    //input vars
	
    //output vars
	
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	
} _WaterHeaterController_t;

//all FBs get a preinit function
int _WaterHeaterController_preinit(_WaterHeaterController_t  *me);

//all FBs get an init function
int _WaterHeaterController_init(_WaterHeaterController_t  *me);

//all FBs get a run function
void _WaterHeaterController_run(_WaterHeaterController_t  *me);

//composite/resource/device FBs get sync functions
void _WaterHeaterController_syncOutputEvents(_WaterHeaterController_t  *me);
void _WaterHeaterController_syncInputEvents(_WaterHeaterController_t  *me);

void _WaterHeaterController_syncOutputData(_WaterHeaterController_t  *me);
void _WaterHeaterController_syncInputData(_WaterHeaterController_t  *me);



#endif
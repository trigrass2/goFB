// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block ConveyorController
#ifndef CONVEYORCONTROLLER_H_
#define CONVEYORCONTROLLER_H_

#include "fbtypes.h"
#include "util.h"



//This is a BFB, so we need an enum type for the state machine
enum ConveyorController_states { STATE_ConveyorController_E_Stop, STATE_ConveyorController_Running, STATE_ConveyorController_Pause };


union ConveyorControllerInputEvents {
	struct {
		UDINT InjectDone;
		UDINT EmergencyStopChanged;
		UDINT LasersChanged;
	} event;
	
};


union ConveyorControllerOutputEvents {
	struct {
		UDINT ConveyorChanged;
		UDINT ConveyorStoppedForInject;
	} event;
	
};


typedef struct {
    //input events
	union ConveyorControllerInputEvents inputEvents;

    //output events
	union ConveyorControllerOutputEvents outputEvents;

    //input vars
	BOOL EmergencyStop;
    BOOL InjectSiteLaser;
    
    //output vars
	BYTE ConveyorSpeed;
    
	//any internal vars (BFBs only)
    BOOL Variable1;
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum ConveyorController_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
	
} ConveyorController_t;

//all FBs get a preinit function
int ConveyorController_preinit(ConveyorController_t  *me);

//all FBs get an init function
int ConveyorController_init(ConveyorController_t  *me);

//all FBs get a run function
void ConveyorController_run(ConveyorController_t  *me);



#endif

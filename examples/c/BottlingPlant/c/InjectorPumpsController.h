// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the interface of Function Block InjectorPumpsController
#ifndef INJECTORPUMPSCONTROLLER_H_
#define INJECTORPUMPSCONTROLLER_H_

#include "fbtypes.h"

//This is a BFB, so we need an enum type for the state machine
enum InjectorPumpsController_states { STATE_InjectorPumpsController_RejectCanister, STATE_InjectorPumpsController_AwaitPump, STATE_InjectorPumpsController_VacuumPump, STATE_InjectorPumpsController_FinishPump, STATE_InjectorPumpsController_StartPump, STATE_InjectorPumpsController_OpenValve, STATE_InjectorPumpsController_StopVacuum };


union InjectorPumpsControllerInputEvents {
	struct {
		UDINT StartPump : 1;
		UDINT EmergencyStopChanged : 1;
		UDINT CanisterPressureChanged : 1;
		UDINT FillContentsAvailableChanged : 1;
		UDINT VacuumTimerElapsed : 1;
	} event;
	UDINT events[1];
};


union InjectorPumpsControllerOutputEvents {
	struct {
		UDINT PumpFinished : 1;
		UDINT RejectCanister : 1;
		UDINT InjectorControlsChanged : 1;
		UDINT FillContentsChanged : 1;
		UDINT StartVacuumTimer : 1;
	} event;
	UDINT events[1];
};


typedef struct {
    //input events
	union InjectorPumpsControllerInputEvents inputEvents;

    //output events
	union InjectorPumpsControllerOutputEvents outputEvents;

    //input vars
	BOOL EmergencyStop;
    BYTE CanisterPressure;
    BYTE FillContentsAvailable;
    
    //output vars
	BOOL InjectorContentsValveOpen;
    BOOL InjectorVacuumRun;
    BOOL InjectorPressurePumpRun;
    BOOL FillContents;
    
	//any internal vars (BFBs only)
    
	//any child FBs (CFBs only)
	
	//resource vars
	
	//resources (Devices only)
	
	//state and trigger (BFBs only)
	enum InjectorPumpsController_states _state; //stores current state
	BOOL _trigger; //indicates if a state transition has occured this tick
	
} InjectorPumpsController_t;

//all FBs get a preinit function
int InjectorPumpsController_preinit(InjectorPumpsController_t  *me);

//all FBs get an init function
int InjectorPumpsController_init(InjectorPumpsController_t  *me);

//all FBs get a run function
void InjectorPumpsController_run(InjectorPumpsController_t  *me);

//basic FBs have a number of algorithm functions

void InjectorPumpsController_StartVacuum(InjectorPumpsController_t  *me);

void InjectorPumpsController_ClearControls(InjectorPumpsController_t  *me);

void InjectorPumpsController_OpenValve(InjectorPumpsController_t  *me);

void InjectorPumpsController_StartPump(InjectorPumpsController_t  *me);


#endif

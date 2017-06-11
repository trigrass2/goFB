// This file is generated by FBC.

#ifndef INJECTORPUMPSCONTROLLER_H_
#define INJECTORPUMPSCONTROLLER_H_

#include "fbtypes.h"

typedef union {
    struct {
        UDINT StartPump ; // 
        UDINT EmergencyStopChanged ; // 
        UDINT CanisterPressureChanged ; // 
        UDINT FillContentsAvailableChanged ; // 
        UDINT VacuumTimerElapsed ; // 
    } event;
} InjectorPumpsControllerIEvents;

typedef union {
    struct {
        UDINT PumpFinished ; // 
        UDINT RejectCanister ; // 
        UDINT InjectorControlsChanged ; // 
        UDINT FillContentsChanged ; // 
        UDINT StartVacuumTimer ; // 
    } event;
} InjectorPumpsControllerOEvents;

typedef struct {
    UINT _state;
    BOOL _entered;
    InjectorPumpsControllerIEvents _input;
    BOOL EmergencyStop; // 
    BOOL _EmergencyStop;
    BYTE CanisterPressure; // 
    BYTE _CanisterPressure;
    BYTE FillContentsAvailable; // 
    BYTE _FillContentsAvailable;
    InjectorPumpsControllerOEvents _output;
    BOOL InjectorContentsValveOpen; // 
    BOOL _InjectorContentsValveOpen;
    BOOL InjectorVacuumRun; // 
    BOOL _InjectorVacuumRun;
    BOOL InjectorPressurePumpRun; // 
    BOOL _InjectorPressurePumpRun;
    BOOL FillContents; // 
    BOOL _FillContents;
} InjectorPumpsController;

/* Function block initialization function */
void InjectorPumpsControllerinit(InjectorPumpsController* me);

/* Function block execution function */
void InjectorPumpsControllerrun(InjectorPumpsController* me);

/* ECC algorithms */
void InjectorPumpsController_StartVacuum(InjectorPumpsController* me);
void InjectorPumpsController_ClearControls(InjectorPumpsController* me);
void InjectorPumpsController_OpenValve(InjectorPumpsController* me);
void InjectorPumpsController_StartPump(InjectorPumpsController* me);

#endif // INJECTORPUMPSCONTROLLER_H_
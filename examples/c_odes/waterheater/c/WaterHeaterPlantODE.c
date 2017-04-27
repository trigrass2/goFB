// This file has been automatically generated by goFB and should not be edited by hand
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

// This file represents the implementation of the ODE / Hybrid Automata Function Block for WaterHeaterPlantODE
#include "WaterHeaterPlantODE.h"


/* WaterHeaterPlantODE_preinit() is required to be called to 
 * initialise an instance of WaterHeaterPlantODE. 
 * It sets all I/O values to zero.
 */
int WaterHeaterPlantODE_preinit(WaterHeaterPlantODE_t  *me) {
	//if there are input events, reset them
	me->inputEvents.event.HeatChange = 0;
	me->inputEvents.event.Tick = 0;
	
	//if there are output events, reset them
	me->outputEvents.event.Ychange = 0;
	
	//if there are input vars with default values, set them
	
	//if there are output vars with default values, set them
	
	//if there are internal vars with default values, set them (BFBs only)
	
	//if there are resource vars with default values, set them
	
	//if there are resources with set parameters, set them
	
	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	
	//if this is a BFB/odeFB, set start state so that the start state is properly executed and _trigger if necessary
	me->_state = STATE_WaterHeaterPlantODE_Start;
	me->_trigger = true;
	
	me->cvode_mem = NULL;
	me->Tcurr = 0;
	me->Tnext = 0;
	me->T0 = 0;
	
	
	return 0;
}

/* WaterHeaterPlantODE_init() is required to be called to 
 * set up an instance of WaterHeaterPlantODE. 
 * It passes around configuration data.
 */
int WaterHeaterPlantODE_init(WaterHeaterPlantODE_t  *me) {
	//pass in any parameters on this level
	
	
	

	//perform a data copy to all children (if any present) (can move config data around, doesn't do anything otherwise)
	

	//if there are fb children (CFBs/Devices/Resources only), call this same function on them
	
	

	return 0;
}




//algorithms


static int WaterHeaterPlantODE_t1_ode_ode_f(realtype t, N_Vector ode_solution, N_Vector ode_solution_dot, void *user_data) {
	//AUTOGENERATED CODE: this function represents the ODE in WaterHeaterPlantODE's t1_ode algorithm
	//it is in a format that CVODE can process.
	WaterHeaterPlantODE_t *me = (WaterHeaterPlantODE_t*)user_data;
	
	NV_Ith_S(ode_solution_dot, 0) = 0;
	
	return 0;
}

static int WaterHeaterPlantODE_t1_ode_ode_g(realtype t, N_Vector ode_solution, realtype *gout, void *user_data) {
	//AUTOGENERATED CODE: this function represents the roots of the ODE in WaterHeaterPlantODE's t1_ode algorithm
	//it is in a format that CVODE can process.
	
	gout[0] = NV_Ith_S(ode_solution, 0) - (0);
	
	return 0;
}

void WaterHeaterPlantODE_t1_ode(WaterHeaterPlantODE_t *me) {
	//AUTOGENERATED CODE: this function manages iterations of the ODE in WaterHeaterPlantODE's t1_ode algorithm
	//It calls the CVODE solver and sets the outputs of the HA FB.
	me->Tnext += me->DeltaTime;
	int flag = CVode(me->cvode_mem, me->Tnext, me->ode_solution, &me->Tcurr, CV_NORMAL);
	if (flag < 0) {
		fprintf(stderr, "Error in CVode: %d\n", flag);
		while(1);
	}
	
	me->X = NV_Ith_S(me->ode_solution, 0);
	
	me->Y = me->X;
	
}




void WaterHeaterPlantODE_t1_setup_0(WaterHeaterPlantODE_t *me, CVRhsFn ode_f, CVRootFn ode_g) {
	//AUTOGENERATED CODE: this algorithm specifies the initialization of a CVODE SUNDIALS solver and was parsed from the algorithm's text field
	int flag;
	
	//specify tolerances
	realtype reltol = 1e-6;
    realtype abstol = 1e-8;

	//free solver if it is initialized
	if(me->cvode_mem != NULL) {
		CVodeFree(&me->cvode_mem);
		N_VDestroy_Serial(me->ode_solution);  /* Free y vector */
	}

	//create solver
	me->ode_solution = N_VNew_Serial(1); //length of initial values
	me->cvode_mem = CVodeCreate(CV_ADAMS, CV_FUNCTIONAL);
	if (me->cvode_mem == 0) {
		fprintf(stderr, "Error in CVodeMalloc: could not allocate\n");
		while(1);
	}

	//specify initial values
	
	NV_Ith_S(me->ode_solution, 0) = 20;
	
		
	me->T0 = me->Tcurr; //set T0 to whatever real time we were counting from before
	me->Tnext = me->Tcurr; //this will always be T0 + some time, but the increment happens inside the _f function

	//initialize solver with pointer to values
	flag = CVodeInit(me->cvode_mem, ode_f, me->T0, me->ode_solution);
    if (flag < 0) {
		fprintf(stderr, "Error in CVodeMalloc: %d\n", flag);
		while(1);
    }

	flag = CVodeSetUserData(me->cvode_mem, me);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeSetUserData: %d\n", flag);
		while(1);
    }


	//set solver tolerances
	flag = CVodeSStolerances(me->cvode_mem, reltol, abstol);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeSStolerances: %d\n", flag);
		while(1);
	}

	//set root function
	flag = CVodeRootInit(me->cvode_mem, 1, ode_g);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeRootInit: %d\n", flag);
		while(1);
	}
}



static int WaterHeaterPlantODE_t2_ode_ode_f(realtype t, N_Vector ode_solution, N_Vector ode_solution_dot, void *user_data) {
	//AUTOGENERATED CODE: this function represents the ODE in WaterHeaterPlantODE's t2_ode algorithm
	//it is in a format that CVODE can process.
	WaterHeaterPlantODE_t *me = (WaterHeaterPlantODE_t*)user_data;
	
	NV_Ith_S(ode_solution_dot, 0) = me->K * (me->H - NV_Ith_S(ode_solution, 0));
	
	return 0;
}

static int WaterHeaterPlantODE_t2_ode_ode_g(realtype t, N_Vector ode_solution, realtype *gout, void *user_data) {
	//AUTOGENERATED CODE: this function represents the roots of the ODE in WaterHeaterPlantODE's t2_ode algorithm
	//it is in a format that CVODE can process.
	
	gout[0] = NV_Ith_S(ode_solution, 0) - (100);
	
	return 0;
}

void WaterHeaterPlantODE_t2_ode(WaterHeaterPlantODE_t *me) {
	//AUTOGENERATED CODE: this function manages iterations of the ODE in WaterHeaterPlantODE's t2_ode algorithm
	//It calls the CVODE solver and sets the outputs of the HA FB.
	me->Tnext += me->DeltaTime;
	int flag = CVode(me->cvode_mem, me->Tnext, me->ode_solution, &me->Tcurr, CV_NORMAL);
	if (flag < 0) {
		fprintf(stderr, "Error in CVode: %d\n", flag);
		while(1);
	}

	me->X = NV_Ith_S(me->ode_solution, 0);
	
	me->Y = me->X;
	
}




void WaterHeaterPlantODE_x_prime_eq_x___y_eq_x(WaterHeaterPlantODE_t *me, CVRhsFn ode_f, CVRootFn ode_g) {
	//AUTOGENERATED CODE: this algorithm specifies the initialization of a CVODE SUNDIALS solver and was parsed from the algorithm's text field
	int flag;
	
	//specify tolerances
	realtype reltol = 1e-6;
    realtype abstol = 1e-8;

	//free solver if it is initialized
	if(me->cvode_mem != NULL) {
		CVodeFree(&me->cvode_mem);
		N_VDestroy_Serial(me->ode_solution);  /* Free y vector */
	}

	//create solver
	me->ode_solution = N_VNew_Serial(1); //length of initial values
	me->cvode_mem = CVodeCreate(CV_ADAMS, CV_FUNCTIONAL);
	if (me->cvode_mem == 0) {
		fprintf(stderr, "Error in CVodeMalloc: could not allocate\n");
		while(1);
	}

	//specify initial values
	
	NV_Ith_S(me->ode_solution, 0) = me->X;
	
		
	me->T0 = me->Tcurr; //set T0 to whatever real time we were counting from before
	me->Tnext = me->Tcurr; //this will always be T0 + some time, but the increment happens inside the _f function

	//initialize solver with pointer to values
	flag = CVodeInit(me->cvode_mem, ode_f, me->T0, me->ode_solution);
    if (flag < 0) {
		fprintf(stderr, "Error in CVodeMalloc: %d\n", flag);
		while(1);
    }

	flag = CVodeSetUserData(me->cvode_mem, me);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeSetUserData: %d\n", flag);
		while(1);
    }


	//set solver tolerances
	flag = CVodeSStolerances(me->cvode_mem, reltol, abstol);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeSStolerances: %d\n", flag);
		while(1);
	}

	//set root function
	flag = CVodeRootInit(me->cvode_mem, 1, ode_g);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeRootInit: %d\n", flag);
		while(1);
	}
}



static int WaterHeaterPlantODE_t3_ode_ode_f(realtype t, N_Vector ode_solution, N_Vector ode_solution_dot, void *user_data) {
	//AUTOGENERATED CODE: this function represents the ODE in WaterHeaterPlantODE's t3_ode algorithm
	//it is in a format that CVODE can process.
	WaterHeaterPlantODE_t *me = (WaterHeaterPlantODE_t*)user_data;
	
	NV_Ith_S(ode_solution_dot, 0) = 0;
	
	return 0;
}

static int WaterHeaterPlantODE_t3_ode_ode_g(realtype t, N_Vector ode_solution, realtype *gout, void *user_data) {
	//AUTOGENERATED CODE: this function represents the roots of the ODE in WaterHeaterPlantODE's t3_ode algorithm
	//it is in a format that CVODE can process.
	
	gout[0] = NV_Ith_S(ode_solution, 0) - (0);
	
	return 0;
}

void WaterHeaterPlantODE_t3_ode(WaterHeaterPlantODE_t *me) {
	//AUTOGENERATED CODE: this function manages iterations of the ODE in WaterHeaterPlantODE's t3_ode algorithm
	//It calls the CVODE solver and sets the outputs of the HA FB.
	me->Tnext += me->DeltaTime;
	int flag = CVode(me->cvode_mem, me->Tnext, me->ode_solution, &me->Tcurr, CV_NORMAL);
	if (flag < 0) {
		fprintf(stderr, "Error in CVode: %d\n", flag);
		while(1);
	}
	
	me->X = NV_Ith_S(me->ode_solution, 0);
	
	me->Y = me->X;
	
}




static int WaterHeaterPlantODE_t4_ode_ode_f(realtype t, N_Vector ode_solution, N_Vector ode_solution_dot, void *user_data) {
	//AUTOGENERATED CODE: this function represents the ODE in WaterHeaterPlantODE's t4_ode algorithm
	//it is in a format that CVODE can process.
	WaterHeaterPlantODE_t *me = (WaterHeaterPlantODE_t*)user_data;
	
	NV_Ith_S(ode_solution_dot, 0) = -me->K * NV_Ith_S(ode_solution, 0);
	
	return 0;
}

static int WaterHeaterPlantODE_t4_ode_ode_g(realtype t, N_Vector ode_solution, realtype *gout, void *user_data) {
	//AUTOGENERATED CODE: this function represents the roots of the ODE in WaterHeaterPlantODE's t4_ode algorithm
	//it is in a format that CVODE can process.
	
	gout[0] = NV_Ith_S(ode_solution, 0) - (20);
	
	return 0;
}

void WaterHeaterPlantODE_t4_ode(WaterHeaterPlantODE_t *me) {
	//AUTOGENERATED CODE: this function manages iterations of the ODE in WaterHeaterPlantODE's t4_ode algorithm
	//It calls the CVODE solver and sets the outputs of the HA FB.
	me->Tnext += me->DeltaTime;
	int flag = CVode(me->cvode_mem, me->Tnext, me->ode_solution, &me->Tcurr, CV_NORMAL);
	if (flag < 0) {
		fprintf(stderr, "Error in CVode: %d\n", flag);
		while(1);
	}
	
	me->X = NV_Ith_S(me->ode_solution, 0);
	
	me->Y = me->X;
	
}





/* WaterHeaterPlantODE_run() executes a single tick of an
 * instance of WaterHeaterPlantODE according to synchronous semantics.
 * Notice that it does NOT perform any I/O - synchronisation
 * will need to be done in the parent.
 * Also note that on the first run of this function, trigger will be set
 * to true, meaning that on the very first run no next state logic will occur.
 */
void WaterHeaterPlantODE_run(WaterHeaterPlantODE_t *me) {
	//if there are output events, reset them
	
	me->outputEvents.event.Ychange = 0;
	

	repeat: //ode ECCs have ode setup states that aren't maintained for a tick, 
			//so they are passed through, so they need a place to goto 

	me->_trigger = false;


	//next state logic
	if(me->_trigger == false) {
		switch(me->_state) {
		case STATE_WaterHeaterPlantODE_Start:
			if(me->inputEvents.event.Tick) {
				me->_state = STATE_WaterHeaterPlantODE_t1_enter_0;
				me->_trigger = true;
			};
			break;
		case STATE_WaterHeaterPlantODE_t1_enter_0:
			if(true) {
				me->_state = STATE_WaterHeaterPlantODE_t1;
				me->_trigger = true;
			};
			break;
		case STATE_WaterHeaterPlantODE_t1:
			if(me->inputEvents.event.Tick && me->inputEvents.event.HeatChange && (me->Heat)) {
				me->_state = STATE_WaterHeaterPlantODE_t2_enter_0;
				me->_trigger = true;
			} else if(me->inputEvents.event.Tick) {
				me->_state = STATE_WaterHeaterPlantODE_t1;
				me->_trigger = true;
			};
			break;
		case STATE_WaterHeaterPlantODE_t2_enter_0:
			if(true) {
				me->_state = STATE_WaterHeaterPlantODE_t2;
				me->_trigger = true;
			};
			break;
		case STATE_WaterHeaterPlantODE_t2:
			if(me->inputEvents.event.Tick && me->X == 100) {
				me->_state = STATE_WaterHeaterPlantODE_t3_enter_0;
				me->_trigger = true;
			} else if(me->inputEvents.event.Tick && me->inputEvents.event.HeatChange && ( ! me->Heat)) {
				me->_state = STATE_WaterHeaterPlantODE_t4_enter_1;
				me->_trigger = true;
			} else if(me->inputEvents.event.Tick) {
				me->_state = STATE_WaterHeaterPlantODE_t2;
				me->_trigger = true;
			};
			break;
		case STATE_WaterHeaterPlantODE_t1_enter_1:
			if(true) {
				me->_state = STATE_WaterHeaterPlantODE_t1;
				me->_trigger = true;
			};
			break;
		case STATE_WaterHeaterPlantODE_t4:
			if(me->inputEvents.event.Tick && me->X == 20) {
				me->_state = STATE_WaterHeaterPlantODE_t1_enter_1;
				me->_trigger = true;
			} else if(me->inputEvents.event.Tick && me->inputEvents.event.HeatChange && (me->Heat)) {
				me->_state = STATE_WaterHeaterPlantODE_t2_enter_1;
				me->_trigger = true;
			} else if(me->inputEvents.event.Tick) {
				me->_state = STATE_WaterHeaterPlantODE_t4;
				me->_trigger = true;
			};
			break;
		case STATE_WaterHeaterPlantODE_t3_enter_0:
			if(true) {
				me->_state = STATE_WaterHeaterPlantODE_t3;
				me->_trigger = true;
			};
			break;
		case STATE_WaterHeaterPlantODE_t3:
			if(me->inputEvents.event.Tick && me->inputEvents.event.HeatChange && ( ! me->Heat)) {
				me->_state = STATE_WaterHeaterPlantODE_t4_enter_0;
				me->_trigger = true;
			} else if(me->inputEvents.event.Tick) {
				me->_state = STATE_WaterHeaterPlantODE_t3;
				me->_trigger = true;
			};
			break;
		case STATE_WaterHeaterPlantODE_t4_enter_0:
			if(true) {
				me->_state = STATE_WaterHeaterPlantODE_t4;
				me->_trigger = true;
			};
			break;
		case STATE_WaterHeaterPlantODE_t2_enter_1:
			if(true) {
				me->_state = STATE_WaterHeaterPlantODE_t2;
				me->_trigger = true;
			};
			break;
		case STATE_WaterHeaterPlantODE_t4_enter_1:
			if(true) {
				me->_state = STATE_WaterHeaterPlantODE_t4;
				me->_trigger = true;
			};
			break;
		
		}
	}
	
	if(me->_trigger == true) {
		switch(me->_state) {
		case STATE_WaterHeaterPlantODE_Start:
			
			break;
		case STATE_WaterHeaterPlantODE_t1_enter_0:
			
			//init all ode algorithms that this state feeds into
			WaterHeaterPlantODE_t1_setup_0(me, WaterHeaterPlantODE_t1_ode_ode_f, WaterHeaterPlantODE_t1_ode_ode_g);
			
			//this is an ODE setup state (ODE_init) so we need to repeat this whole function body
			goto repeat;
			break;
		case STATE_WaterHeaterPlantODE_t1:
			
			WaterHeaterPlantODE_t1_ode(me);
			me->outputEvents.event.Ychange = 1;
			
			break;
		case STATE_WaterHeaterPlantODE_t2_enter_0:
			
			//init all ode algorithms that this state feeds into
			WaterHeaterPlantODE_x_prime_eq_x___y_eq_x(me, WaterHeaterPlantODE_t2_ode_ode_f, WaterHeaterPlantODE_t2_ode_ode_g);
			
			//this is an ODE setup state (ODE_init) so we need to repeat this whole function body
			goto repeat;
			break;
		case STATE_WaterHeaterPlantODE_t2:
			
			WaterHeaterPlantODE_t2_ode(me);
			me->outputEvents.event.Ychange = 1;
			
			break;
		case STATE_WaterHeaterPlantODE_t1_enter_1:
			
			//init all ode algorithms that this state feeds into
			WaterHeaterPlantODE_x_prime_eq_x___y_eq_x(me, WaterHeaterPlantODE_t1_ode_ode_f, WaterHeaterPlantODE_t1_ode_ode_g);
			
			//this is an ODE setup state (ODE_init) so we need to repeat this whole function body
			goto repeat;
			break;
		case STATE_WaterHeaterPlantODE_t4:
			
			WaterHeaterPlantODE_t4_ode(me);
			me->outputEvents.event.Ychange = 1;
			
			break;
		case STATE_WaterHeaterPlantODE_t3_enter_0:
			
			//init all ode algorithms that this state feeds into
			WaterHeaterPlantODE_x_prime_eq_x___y_eq_x(me, WaterHeaterPlantODE_t3_ode_ode_f, WaterHeaterPlantODE_t3_ode_ode_g);
			
			//this is an ODE setup state (ODE_init) so we need to repeat this whole function body
			goto repeat;
			break;
		case STATE_WaterHeaterPlantODE_t3:
			
			WaterHeaterPlantODE_t3_ode(me);
			me->outputEvents.event.Ychange = 1;
			
			break;
		case STATE_WaterHeaterPlantODE_t4_enter_0:
			
			//init all ode algorithms that this state feeds into
			WaterHeaterPlantODE_x_prime_eq_x___y_eq_x(me, WaterHeaterPlantODE_t4_ode_ode_f, WaterHeaterPlantODE_t4_ode_ode_g);
			
			//this is an ODE setup state (ODE_init) so we need to repeat this whole function body
			goto repeat;
			break;
		case STATE_WaterHeaterPlantODE_t2_enter_1:
			
			//init all ode algorithms that this state feeds into
			WaterHeaterPlantODE_x_prime_eq_x___y_eq_x(me, WaterHeaterPlantODE_t2_ode_ode_f, WaterHeaterPlantODE_t2_ode_ode_g);
			
			//this is an ODE setup state (ODE_init) so we need to repeat this whole function body
			goto repeat;
			break;
		case STATE_WaterHeaterPlantODE_t4_enter_1:
			
			//init all ode algorithms that this state feeds into
			WaterHeaterPlantODE_x_prime_eq_x___y_eq_x(me, WaterHeaterPlantODE_t4_ode_ode_f, WaterHeaterPlantODE_t4_ode_ode_g);
			
			//this is an ODE setup state (ODE_init) so we need to repeat this whole function body
			goto repeat;
			break;
		
		}
	}
	
	
	printf("T: %f\tY: %f\n", me->Tcurr, me->Y);


}



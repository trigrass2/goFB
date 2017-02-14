// This file has been automatically generated by goFB
// Compiler written by Hammond Pearce and available at github.com/kiwih/goFB

//This is the main file for the iec61499 network with topMANY as the top level block

#include "topMANY.h"

//put a copy of the top level block into global memory
topMANY_t mytopMANY;

int main() {
	if(topMANY_preinit(&mytopMANY) != 0) {
		printf("Failed to preinitialize.");
		return 1;
	}
	if(topMANY_init(&mytopMANY) != 0) {
		printf("Failed to initialize.");
		return 1;
	}
	int tickNum = 0;
	do {
		printf("=====TICK %i=====\n",tickNum);
		topMANY_syncOutputEvents(&mytopMANY);
		topMANY_syncInputEvents(&mytopMANY);

		topMANY_syncOutputData(&mytopMANY);
		topMANY_syncInputData(&mytopMANY);
		
		topMANY_run(&mytopMANY);
	} while(tickNum++ < 10);

	return 0;
}


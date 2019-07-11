#include <iostream>
#include <vector>

#include "NodeL.cc"
//#include "UE.cc"

#define SIMEND 2
#define NUM_UE 2

int main(void) {

	auto nodeL = new NodeL(0);
	auto ueList = new std::vector<UE*>();
	for (int i = 0; i < NUM_UE; i++)
		ueList->push_back(new UE(i));
	
	for (int i = 0; i < SIMEND; i++)  {
		char msg;
		msg = nodeL->out();
		for (UE* ue : *ueList) {
			ue->in(msg);
			if (ue->out() != '\0')
				msg = ue->out();
		}
		nodeL->in(msg);
		
		nodeL->tick();
		for (UE* ue : *ueList) {
			ue->tick();
		}
	}
}

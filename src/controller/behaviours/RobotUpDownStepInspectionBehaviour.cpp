#include "RobotUpDownStepInspectionBehaviour.h"
#include "HeadPitchDownPosition.h"
#include "HeadPitchTopPosition.h"
#include "HeadPitchBehaviour.h"

namespace var
{   
   //Constructor con behaviours
   RobotUpDownStepInspectionBehaviour::RobotUpDownStepInspectionBehaviour(MoveGenerator* moveGenerator) :
      SuccessionMoveBehaviour(moveGenerator)
   {
   		//Posicionar mirando abajo
			this->addBehaviour(new HeadPitchDownPosition(moveGenerator, 0.1, 6000, false));
			//Mover cabeza hacia arriba para inspeccionar
			this->addBehaviour(new HeadPitchBehaviour(moveGenerator, 0, -50, 2, 0.1, 1200, true));
			//Posicionar mirando hacia arriba
			this->addBehaviour(new HeadPitchTopPosition(moveGenerator, 0.1, 6000, false));
			//Mover cabeza hacia abajo para inspeccionar
			this->addBehaviour(new HeadPitchBehaviour(moveGenerator, 0, 50, 2, 0.1, 1200, true));
   }
   
   //Destructor
   RobotUpDownStepInspectionBehaviour::~RobotUpDownStepInspectionBehaviour()
   {
   }
}

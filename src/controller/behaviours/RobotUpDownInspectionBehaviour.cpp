#include "RobotUpDownInspectionBehaviour.h"
#include "RobotUpDownNoBaseTurnInspectionBehaviour.h"
#include "HeadYawRightPosition.h"
#include "BaseTurnBehaviour.h"

namespace var
{   
   //Constructor con behaviours
   RobotUpDownInspectionBehaviour::RobotUpDownInspectionBehaviour(MoveGenerator* moveGenerator) :
      IterativeMoveBehaviour(moveGenerator,2)
   {
   		//Posicionar mirando a la derecha
			this->addBehaviour(new HeadYawRightPosition(moveGenerator, 0.1, 6000, false));
			//Realizar inspección arriba-abajo desplazando la cabeza a la izquierda
			this->addBehaviour(new RobotUpDownNoBaseTurnInspectionBehaviour(moveGenerator, 5, 180.0/5.0));
			//Girar la base hacia la izquierda para ampliar la visión
			this->addBehaviour(new BaseTurnBehaviour(moveGenerator, 0, 180, 180, 10, 1500, false));
   }
   
   //Destructor
   RobotUpDownInspectionBehaviour::~RobotUpDownInspectionBehaviour()
   {
   }
}

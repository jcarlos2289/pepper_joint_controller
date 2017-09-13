#include "RobotRightInspectionBehaviour.h"
#include "HeadYawLeftPosition.h"
#include "HeadYawBehaviour.h"
#include "BaseTurnBehaviour.h"

namespace var
{   
   //Constructor con behaviours
   RobotRightInspectionBehaviour::RobotRightInspectionBehaviour(MoveGenerator* moveGenerator) :
      IterativeMoveBehaviour(moveGenerator,4)
   {
   		//Posicionar mirando a la izquierda
			this->addBehaviour(new HeadYawLeftPosition(moveGenerator, 0.1, 6000, false));
			//Mover cabeza a la derecha para inspeccionar
			this->addBehaviour(new HeadYawBehaviour(moveGenerator, 0, -180, 2, 0.1, 1200, true));
			//Girar la base hacia la derecha para ampliar la visión
			this->addBehaviour(new BaseTurnBehaviour(moveGenerator, 0, -90, 90, 10, 1500, false));
   }
   
   //Destructor
   RobotRightInspectionBehaviour::~RobotRightInspectionBehaviour()
   {
   }
}

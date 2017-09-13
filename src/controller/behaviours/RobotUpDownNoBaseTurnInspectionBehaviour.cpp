#include "RobotUpDownNoBaseTurnInspectionBehaviour.h"
#include "RobotUpDownStepInspectionBehaviour.h"
#include "HeadYawBehaviour.h"
#include <math.h> 

namespace var
{   
   //Constructor con behaviours
   RobotUpDownNoBaseTurnInspectionBehaviour::RobotUpDownNoBaseTurnInspectionBehaviour(MoveGenerator* moveGenerator, 
      const double& gradosHorizontalPorMovimiento, const int& iteraciones) : IterativeMoveBehaviour(moveGenerator,iteraciones)
   {
         //Realizar movimiento de inspección abajo-arriba y arriba-abajo
			this->addBehaviour(new RobotUpDownStepInspectionBehaviour(moveGenerator));
			//Mover cabeza hacia la derecha para mirar hacia otra zona
			this->addBehaviour(new HeadYawBehaviour(moveGenerator, 0, 
			gradosHorizontalPorMovimiento, fabs(gradosHorizontalPorMovimiento), 0.1, 1200, false));
   }
   
   //Destructor
   RobotUpDownNoBaseTurnInspectionBehaviour::~RobotUpDownNoBaseTurnInspectionBehaviour()
   {
   }
}

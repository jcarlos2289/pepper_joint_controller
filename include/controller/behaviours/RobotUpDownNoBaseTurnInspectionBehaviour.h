#ifndef ROBOT_UP_DOWN_NO_BASE_TURN_INSPECTION_BEHAVIOUR_H
#define ROBOT_UP_DOWN_NO_BASE_TURN_INSPECTION_BEHAVIOUR_H

#include "IterativeMoveBehaviour.h"

namespace var
{
   //Clase para controlar la inspección arriba-abajo sin mover la base
   class RobotUpDownNoBaseTurnInspectionBehaviour : public IterativeMoveBehaviour
   {
      public:
         //Constructor con behaviours
         RobotUpDownNoBaseTurnInspectionBehaviour(MoveGenerator* moveGenerator, 
            const double& gradosHorizontalPorMovimiento, const int& iteraciones);
         //Destructor
         virtual ~RobotUpDownNoBaseTurnInspectionBehaviour();
   };
}

#endif

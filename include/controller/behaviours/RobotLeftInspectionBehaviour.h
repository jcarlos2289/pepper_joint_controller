#ifndef ROBOT_LEFT_INSPECTION_BEHAVIOUR_H
#define ROBOT_LEFT_INSPECTION_BEHAVIOUR_H

#include "IterativeMoveBehaviour.h"

namespace var
{
   //Clase para controlar una la inspección hacia la izquierda
   class RobotLeftInspectionBehaviour : public IterativeMoveBehaviour
   {
      public:
         //Constructor con behaviours
         RobotLeftInspectionBehaviour(MoveGenerator* moveGenerator);
         //Destructor
         virtual ~RobotLeftInspectionBehaviour();
   };
}

#endif

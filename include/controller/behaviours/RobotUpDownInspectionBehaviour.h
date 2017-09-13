#ifndef ROBOT_UP_DOWN_INSPECTION_BEHAVIOUR_H
#define ROBOT_UP_DOWN_INSPECTION_BEHAVIOUR_H

#include "IterativeMoveBehaviour.h"

namespace var
{
   //Clase para controlar una la inspección hacia la derecha
   class RobotUpDownInspectionBehaviour : public IterativeMoveBehaviour
   {
      public:
         //Constructor con behaviours
         RobotUpDownInspectionBehaviour(MoveGenerator* moveGenerator);
         //Destructor
         virtual ~RobotUpDownInspectionBehaviour();
   };
}

#endif

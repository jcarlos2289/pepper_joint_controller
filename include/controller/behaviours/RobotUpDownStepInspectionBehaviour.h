#ifndef ROBOT_UP_DOWN_STEP_INSPECTION_BEHAVIOUR_H
#define ROBOT_UP_DOWN_STEP_INSPECTION_BEHAVIOUR_H

#include "SuccessionMoveBehaviour.h"

namespace var
{
   //Clase para controlar una la inspección parcial hacia arriba y hacia abajo
   class RobotUpDownStepInspectionBehaviour : public SuccessionMoveBehaviour
   {
      public:
         //Constructor con behaviours
         RobotUpDownStepInspectionBehaviour(MoveGenerator* moveGenerator);
         //Destructor
         virtual ~RobotUpDownStepInspectionBehaviour();
   };
}

#endif

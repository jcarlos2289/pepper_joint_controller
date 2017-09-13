#ifndef ROBOT_RIGHT_INSPECTION_BEHAVIOUR_H
#define ROBOT_RIGHT_INSPECTION_BEHAVIOUR_H

#include "IterativeMoveBehaviour.h"

namespace var
{
   //Clase para controlar una la inspección hacia la derecha
   class RobotRightInspectionBehaviour : public IterativeMoveBehaviour
   {
      public:
         //Constructor con behaviours
         RobotRightInspectionBehaviour(MoveGenerator* moveGenerator);
         //Destructor
         virtual ~RobotRightInspectionBehaviour();
   };
}

#endif

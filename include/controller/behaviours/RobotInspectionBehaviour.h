#ifndef ROBOT_INSPECTION_BEHAVIOUR_H
#define ROBOT_INSPECTION_BEHAVIOUR_H

#include "SuccessionMoveBehaviour.h"

namespace var
{
   class RobotInspectionBehaviour : public SuccessionMoveBehaviour
   {
      public:
        //Constructor
        RobotInspectionBehaviour(MoveGenerator* moveGenerator);
        
        //Destructor
        virtual ~RobotInspectionBehaviour();
   };
}

#endif

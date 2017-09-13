#ifndef HEAD_YAW_LEFT_POSITION_H
#define HEAD_YAW_LEFT_POSITION_H

#include "AbsoluteJointPosition.h"
#include "SuccessionMoveBehaviour.h"

namespace var
{
   //Poner la articulación yaw del robot a la izquierda
   class HeadYawLeftPosition : public SuccessionMoveBehaviour
   {
      public:
         //Constructor
         HeadYawLeftPosition(MoveGenerator* moveGenerator, const double& speed, 
            const double &millis, const bool& reconocerObjetos);
         //Destructor
         virtual ~HeadYawLeftPosition();
   };
}

#endif

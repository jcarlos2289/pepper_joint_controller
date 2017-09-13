#ifndef HEAD_YAW_RIGHT_POSITION_H
#define HEAD_YAW_RIGHT_POSITION_H

#include "AbsoluteJointPosition.h"
#include "SuccessionMoveBehaviour.h"

namespace var
{
   //Poner la articulación yaw del robot a la derecha
   class HeadYawRightPosition : public SuccessionMoveBehaviour
   {
      public:
         //Constructor
         HeadYawRightPosition(MoveGenerator* moveGenerator, const double& speed, 
            const double &millis, const bool& reconocerObjetos);
         //Destructor
         virtual ~HeadYawRightPosition();
   };
}

#endif

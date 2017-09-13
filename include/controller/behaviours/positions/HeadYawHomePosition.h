#ifndef HEAD_YAW_HOME_POSITION_H
#define HEAD_YAW_HOME_POSITION_H

#include "AbsoluteJointPosition.h"

namespace var
{
   //Poner la articulación yaw del robot a 0
   class HeadYawHomePosition : public AbsoluteJointPosition
   {
      public:
         //Constructor
         HeadYawHomePosition(MoveGenerator* moveGenerator, const double& speed, 
            const double &millis, const bool& reconocerObjetos);
         //Destructor
         virtual ~HeadYawHomePosition();
   };
}

#endif

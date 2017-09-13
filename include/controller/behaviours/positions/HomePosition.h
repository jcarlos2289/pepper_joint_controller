#ifndef HOME_POSITION_H
#define HOME_POSITION_H

#include "AbsoluteJointPosition.h"

namespace var
{
   //Poner las articulaciones a 0
   class HomePosition : public AbsoluteJointPosition
   {
      public:
         //Constructor
         HomePosition(MoveGenerator* moveGenerator, const double& speed, const double &millis, const bool& reconocerObjetos);
         //Destructor
         virtual ~HomePosition();
   };
}

#endif

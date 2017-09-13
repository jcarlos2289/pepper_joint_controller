#ifndef HEAD_PITCH_HOME_POSITION_H
#define HEAD_PITCH_HOME_POSITION_H

#include "AbsoluteJointPosition.h"

namespace var
{
   //Poner la articulación pitch del robot a 0
   class HeadPitchHomePosition : public AbsoluteJointPosition
   {
      public:
         //Constructor
         HeadPitchHomePosition(MoveGenerator* moveGenerator, const double& speed, 
            const double &millis, const bool& reconocerObjetos);
         //Destructor
         virtual ~HeadPitchHomePosition();
   };
}

#endif

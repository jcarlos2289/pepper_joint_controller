#ifndef HEAD_PITCH_TOP_POSITION_H
#define HEAD_PITCH_TOP_POSITION_H

#include "AbsoluteJointPosition.h"
#include "SuccessionMoveBehaviour.h"

namespace var
{
   //Poner la articulación pitch del robot a mirando hacia arriba
   class HeadPitchTopPosition : public SuccessionMoveBehaviour
   {
      public:
         //Constructor
         HeadPitchTopPosition(MoveGenerator* moveGenerator, const double& speed, 
            const double &millis, const bool& reconocerObjetos);
         //Destructor
         virtual ~HeadPitchTopPosition();
   };
}

#endif

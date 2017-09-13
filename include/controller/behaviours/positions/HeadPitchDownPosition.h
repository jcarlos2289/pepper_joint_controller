#ifndef HEAD_PITCH_DOWN_POSITION_H
#define HEAD_PITCH_DOWN_POSITION_H

#include "AbsoluteJointPosition.h"
#include "SuccessionMoveBehaviour.h"

namespace var
{
   //Poner la articulación pitch del robot a mirando hacia abajo
   class HeadPitchDownPosition : public SuccessionMoveBehaviour
   {
      public:
         //Constructor
         HeadPitchDownPosition(MoveGenerator* moveGenerator, const double& speed, 
            const double &millis, const bool& reconocerObjetos);
         //Destructor
         virtual ~HeadPitchDownPosition();
   };
}

#endif

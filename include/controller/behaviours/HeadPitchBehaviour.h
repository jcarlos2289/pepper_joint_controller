#ifndef HEAD_PITCH_BEHAVIOUR_H
#define HEAD_PITCH_BEHAVIOUR_H

#include "BasicJointMoveBehaviour.h"

namespace var
{
   //Clase con comportamiento simple de movimiento de la cabeza
   class HeadPitchBehaviour : public BasicJointMoveBehaviour
   {
      public:
         //Constructor
         HeadPitchBehaviour(MoveGenerator* moveGenerator, const double& posInicial, const double& posObjetivo, 
            const double& maxStep, const double& speed, const double &millis, const bool& reconocerObjetos);
         //Destructor
         virtual ~HeadPitchBehaviour();
   };
}

#endif

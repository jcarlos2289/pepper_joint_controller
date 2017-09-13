#ifndef LSHOULDER_PITCH_BEHAVIOUR_H
#define LSHOULDER_PITCH_BEHAVIOUR_H

#include "BasicJointMoveBehaviour.h"

namespace var
{
   //Clase con comportamiento simple de movimiento de brazo arriba-abajo
   class LShoulderPitchBehaviour : public BasicJointMoveBehaviour
   {
      public:
         //Constructor
         LShoulderPitchBehaviour(MoveGenerator* moveGenerator, const double& posInicial, const double& posObjetivo, 
            const double& maxStep, const double& speed, const double &millis, const bool& reconocerObjetos);
         //Destructor
         virtual ~LShoulderPitchBehaviour();
   };
}

#endif

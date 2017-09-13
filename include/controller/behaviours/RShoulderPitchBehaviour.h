#ifndef RSHOULDER_PITCH_BEHAVIOUR_H
#define RSHOULDER_PITCH_BEHAVIOUR_H

#include "BasicJointMoveBehaviour.h"

namespace var
{
   //Clase con comportamiento simple de movimiento de brazo derecho arriba-abajo
   class RShoulderPitchBehaviour : public BasicJointMoveBehaviour
   {
      public:
         //Constructor
         RShoulderPitchBehaviour(MoveGenerator* moveGenerator, const double& posInicial, const double& posObjetivo, 
            const double& maxStep, const double& speed, const double &millis, const bool& reconocerObjetos);
         //Destructor
         virtual ~RShoulderPitchBehaviour();
   };
}

#endif

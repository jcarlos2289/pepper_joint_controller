#ifndef BASE_TURN_BEHAVIOUR_H
#define BASE_TURN_BEHAVIOUR_H

#include "BasicBaseMoveBehaviour.h"

namespace var
{
   //Clase con comportamiento simple de giro de base
   class BaseTurnBehaviour : public BasicBaseMoveBehaviour
   {
      public:
         //Constructor
         BaseTurnBehaviour(MoveGenerator* moveGenerator, const double& posInicial, const double& posObjetivo, 
            const double& maxStep, const double& speed, const int& millis, const bool& reconocerObjetos);
         //Destructor
         virtual ~BaseTurnBehaviour();
   };
}

#endif

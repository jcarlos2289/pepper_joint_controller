#ifndef HEAD_YAW_BEHAVIOUR_H
#define HEAD_YAW_BEHAVIOUR_H

#include "BasicJointMoveBehaviour.h"

namespace var
{
   //Clase con comportamiento simple de movimiento de la cabeza
   class HeadYawBehaviour : public BasicJointMoveBehaviour
   {
      public:
         //Constructor
         HeadYawBehaviour(MoveGenerator* moveGenerator, const double& posInicial, const double& posObjetivo, 
            const double& maxStep, const double& speed, const double &millis, const bool& reconocerObjetos);
         //Destructor
         virtual ~HeadYawBehaviour();
   };
}

#endif

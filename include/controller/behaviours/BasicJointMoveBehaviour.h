#ifndef BASIC_JOINT_MOVE_BEHAVIOUR_H
#define BASIC_JOINT_MOVE_BEHAVIOUR_H

#include "BasicMoveBehaviour.h"
#include "PepperJoint.h"

namespace var
{
   //Clase con comportamiento simple de movimiento de articulación relativa
   class BasicJointMoveBehaviour : public BasicMoveBehaviour
   {
      public:
         //Constructor
         BasicJointMoveBehaviour(MoveGenerator* moveGenerator, const PepperJoint& joint, const double& posInicial, 
         const double& posObjetivo, const double& maxStep, const double& speed, const double &millis,
         const bool& reconocerObjetos);
         //Destructor
         virtual ~BasicJointMoveBehaviour();
               
      protected:
         //Realizar movimiento
         virtual bool move();
         
         //Joint del movimiento
         PepperJoint joint;
         //Movimiento máximo por giro
         double maxStep;
         //Velocidad de movimiento de articulación
         double speed;
         //Milisegundos de espera tras enviar la orden
         double millis;
   };
}

#endif

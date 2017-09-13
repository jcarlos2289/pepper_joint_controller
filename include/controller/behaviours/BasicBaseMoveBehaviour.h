#ifndef BASIC_BASE_MOVE_BEHAVIOUR_H
#define BASIC_BASE_MOVE_BEHAVIOUR_H

#include "BasicMoveBehaviour.h"
#include "MoveBaseType.h"

namespace var
{
   //Clase con comportamiento simple de movimiento de articulación relativa
   class BasicBaseMoveBehaviour : public BasicMoveBehaviour
   {
      public:
         //Constructor
         BasicBaseMoveBehaviour(MoveGenerator* moveGenerator, const MoveBaseType& moveType, const double& posInicial, 
         const double& posObjetivo, const double& maxStep, const double& speed, 
         const int& millis, const bool& reconocerObjetos);
         //Destructor
         virtual ~BasicBaseMoveBehaviour();
               
      protected:
         //Realizar movimiento
         virtual bool move();
         
         //Tipo de movimiento de la base
         MoveBaseType moveType;
         //Movimiento máximo por giro
         double maxStep;
         //Velocidad de movimiento de articulación
         double speed;
         //Milisegundos de espera tras enviar la orden de parado
         double millis;
   };
}

#endif

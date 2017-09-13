#ifndef SUCCESSION_MOVE_BEHAVIOUR_H
#define SUCCESSION_MOVE_BEHAVIOUR_H

#include "MoveBehaviour.h"

namespace var
{
   //Clase para controlar una sucesión de movimientos
   class SuccessionMoveBehaviour : public MoveBehaviour
   {
      public:
         //Constructor con behaviours
         SuccessionMoveBehaviour(MoveGenerator* moveGenerator, 
            const std::vector<MoveBehaviour*> &behaviours = std::vector<MoveBehaviour*>());
         //Destructor
         virtual ~SuccessionMoveBehaviour();
         //Reiniciar estado del comportamiento
         virtual void restart();
         //Añadir comportamientos de movimiento
         void addBehaviour(MoveBehaviour* behaviour);
      protected:
         //Realizar movimiento
         virtual bool move();
         //Comprobar si ha terminado el objetivo
         virtual bool checkIfEnded();
         //Comprobar si debe realizarse el reconocimiento de objetos
         virtual bool checkToRecognize();
         
         //Comportamientos
         std::vector<MoveBehaviour*> behaviours;
   };
}

#endif

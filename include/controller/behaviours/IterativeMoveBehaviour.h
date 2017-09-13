#ifndef ITERATIVE_MOVE_BEHAVIOUR_H
#define ITERATIVE_MOVE_BEHAVIOUR_H

#include "SuccessionMoveBehaviour.h"

namespace var
{
   //Clase para controlar una iteración de movimientos sucesivos
   class IterativeMoveBehaviour : public SuccessionMoveBehaviour
   {
      public:
         //Constructor con behaviours
         IterativeMoveBehaviour(MoveGenerator* moveGenerator, const int& numIteraciones, 
            const std::vector<MoveBehaviour*> &behaviours = std::vector<MoveBehaviour*>());
         //Destructor
         virtual ~IterativeMoveBehaviour();
         //Reiniciar estado del comportamiento
         virtual void restart();

      protected:
         //Comprobar si ha terminado el objetivo
         virtual bool checkIfEnded();
         //Número de iteraciones del movimiento
         int numIteracionesActual;
         //Número de iteraciones inicial
         int numIteracionesInicial;
   };
}

#endif

#include "IterativeMoveBehaviour.h"

namespace var
{   
   //Constructor con behaviours
   IterativeMoveBehaviour::IterativeMoveBehaviour(MoveGenerator* moveGenerator, const int& numIteraciones, const std::vector<MoveBehaviour*> &behaviours) :
      SuccessionMoveBehaviour(moveGenerator,behaviours), numIteracionesActual(numIteraciones), numIteracionesInicial(numIteraciones)
   {
   }
   
   //Destructor
   IterativeMoveBehaviour::~IterativeMoveBehaviour()
   {
   }
   
   //Reiniciar estado del comportamiento
   void IterativeMoveBehaviour::restart()
   {
      //Reinicio de clase padre
      SuccessionMoveBehaviour::restart();
      //Reinicio del número de iteraciones
      numIteracionesActual = numIteracionesInicial;
   }
      
   //Comprobar si ha terminado el objetivo
   bool IterativeMoveBehaviour::checkIfEnded()
   {
      //Comprobar su ha terminado el comportamiento de la sucesión
      if(SuccessionMoveBehaviour::checkIfEnded())
      {
         //Decrementar número de iteraciones a realizar
         --numIteracionesActual;
         //Comprobar si el número de iteraciones es 0
         if(numIteracionesActual == 0)
            return true;
         else
         {
            //Reiniciar la sucesión
            SuccessionMoveBehaviour::restart();
            return false;
         }
      }
      else
         return false;
   }
}

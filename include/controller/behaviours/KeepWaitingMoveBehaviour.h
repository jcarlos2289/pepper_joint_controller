#ifndef KEEP_WAITING_MOVE_BEHAVIOUR_H
#define KEEP_WAITING_MOVE_BEHAVIOUR_H

#include "BasicMoveBehaviour.h"

namespace var
{
   //Clase para permanecer a la espera durante el tiempo requerido las veces indicadas
   class KeepWaitingMoveBehaviour : public BasicMoveBehaviour
   {
      public:
         //Constructor
         KeepWaitingMoveBehaviour(MoveGenerator* moveGenerator, const int& iteraciones, 
         const double &millis, const bool& reconocerObjeto);
         //Destructor
         virtual ~KeepWaitingMoveBehaviour();
               
      protected:
         //Realizar movimiento
         virtual bool move();
         
         //Milisegundos de espera tras enviar la orden
         double millis;
   };
}

#endif

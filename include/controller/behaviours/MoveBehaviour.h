#ifndef MOVE_BEHAVIOUR_H
#define MOVE_BEHAVIOUR_H

#include "MoveGenerator.h"

namespace var
{
   //Clase para los comportamientos de movimiento
   class MoveBehaviour
   {
      public:
         //Constructor
         MoveBehaviour(MoveGenerator* moveGenerator);
         //Destructor
         virtual ~MoveBehaviour();
         //Conocer si el comportamiento en su totalidad se ha terminado
         virtual bool hasEnded();
         //Reiniciar estado del comportamiento
         virtual void restart();
         //Ejecutar fase del comportamiento
         virtual bool execute(bool &reconocerObjetos);
         //Comprobar si debe realizarse el reconocimiento de objetos
         virtual bool checkToRecognize() = 0;
         
      protected:
         //Realizar movimiento
         virtual bool move() = 0;
         //Comprobar si ha terminado el objetivo
         virtual bool checkIfEnded() = 0;
         //Variable de fin
         bool ended;
         //Generador de movimiento
         MoveGenerator* moveGenerator;
   };
}

#endif

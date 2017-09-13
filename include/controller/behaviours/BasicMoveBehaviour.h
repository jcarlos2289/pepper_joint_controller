#ifndef BASIC_MOVE_BEHAVIOUR_H
#define BASIC_MOVE_BEHAVIOUR_H

#include "MoveBehaviour.h"

namespace var
{
   //Movimiento básico de una única articulación
   class BasicMoveBehaviour : public MoveBehaviour
   {
      public:
      
      //Constructor
      BasicMoveBehaviour(MoveGenerator* moveGenerator, const double& posInicial, const double& posObjetivo, 
         const double& tolerancia, const bool& reconocerObjetos);
      //Destructor
      virtual ~BasicMoveBehaviour();

      //Reiniciar estado del comportamiento
      virtual void restart();
      //Comprobar si debe realizarse el reconocimiento de objetos
      virtual bool checkToRecognize();
      
      protected:
      //Actualizar posición actual
      virtual void updatePosition(const double& increment);
      //Comprobar si ha terminado el objetivo
      virtual bool checkIfEnded();
      
      //Posición inicial
      double posInicial;
      //Posición actual
      double posActual;
      //Posición objetivo
      double posObjetivo;
      //Tolerancia en la comparativa
      double tolerancia;
      //Realización del reconocimiento de objetos
      bool reconocerObjetos;
   };
}

#endif

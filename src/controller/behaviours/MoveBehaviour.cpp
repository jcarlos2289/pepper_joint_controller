#include "MoveBehaviour.h"

#define DEBUG

namespace var
{
   //Constructor
   MoveBehaviour::MoveBehaviour(MoveGenerator* moveGenerator) : ended(false), moveGenerator(moveGenerator)
   {
   }
   
   //Destructor
   MoveBehaviour::~MoveBehaviour()
   {
   }
   
   //Conocer si el comportamiento en su totalidad se ha terminado
   bool MoveBehaviour::hasEnded()
   {
      return this->ended;
   }
   
   //Reiniciar estado del comportamiento
   void MoveBehaviour::restart() 
   {
      this->ended = false;
   }
   
   //Ejecutar fase del comportamiento
   bool MoveBehaviour::execute(bool &reconocerObjetos)
   {
      //Comprobar si no ha terminado el comportamiento
      if(!this->hasEnded())
      {
         #ifdef DEBUG
         std::cerr<<"Preparando movimiento:"<<std::endl;
         #endif
         //Comprobar si se debe reconocer objetos
         reconocerObjetos = this->checkToRecognize();
         //Realizar movimiento
         this->move();
         //Comprobar si ha terminado
         if(this->checkIfEnded())
            this->ended = true;
      }
      
      return true;
   }

}

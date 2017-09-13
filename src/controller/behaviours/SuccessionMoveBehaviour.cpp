#include "SuccessionMoveBehaviour.h"

namespace var
{   
   //Constructor con behaviours
   SuccessionMoveBehaviour::SuccessionMoveBehaviour(MoveGenerator* moveGenerator, const std::vector<MoveBehaviour*> &behaviours) :
      MoveBehaviour(moveGenerator), behaviours(behaviours)
   {
   }
   
   //Destructor
   SuccessionMoveBehaviour::~SuccessionMoveBehaviour()
   {
      //Limpiar cada comportamiento
      for(unsigned int i=0; i<behaviours.size(); ++i)
      {
         //Liberar memoria del comportamiento
         delete behaviours[i];
      }
   }
   
   //Reiniciar estado del comportamiento
   void SuccessionMoveBehaviour::restart()
   {
      //Reinicio de clase padre
      MoveBehaviour::restart();
      
      //Reinicio del contenedor
      for(unsigned int i=0; i<behaviours.size(); ++i)
      {
         //Reiniciar cada comportamiento
         behaviours[i]->restart();
      }
   }
   
   //Añadir comportamientos de movimiento
   void SuccessionMoveBehaviour::addBehaviour(MoveBehaviour* behaviour)
   {
      this->behaviours.push_back(behaviour);
   }
   
   //Realizar movimiento
   bool SuccessionMoveBehaviour::move()
   {
      for(unsigned int i=0; i<this->behaviours.size(); ++i)
      {
         //Conseguir puntero
         MoveBehaviour* behaviour = behaviours[i];
         //Comprobar si algún comportamientoo no ha terminado
         if(!behaviour->hasEnded())
         {
            bool fakeBool;
            return behaviour->execute(fakeBool);
         }
      }
      
      return false;
   }
   
   //Comprobar si debe realizarse el reconocimiento de objetos
   bool SuccessionMoveBehaviour::checkToRecognize()
   {
      for(unsigned int i=0; i<this->behaviours.size(); ++i)
      {
         //Comprobar si algún comportamientoo no ha terminado
         if(!behaviours[i]->hasEnded())
         {
            return behaviours[i]->checkToRecognize();
         }
      }
      
      return true;
   }
   
   //Comprobar si ha terminado el objetivo
   bool SuccessionMoveBehaviour::checkIfEnded()
   {
      for(unsigned int i=0; i<this->behaviours.size(); ++i)
      {
         //Comprobar si algún comportamientoo no ha terminado
         if(!behaviours[i]->hasEnded())
         {
            return false;
         }
      }
      
      return true;
   }
}

#include "BasicMoveBehaviour.h"
#include <math.h>

namespace var
{
    //Constructor
    BasicMoveBehaviour::BasicMoveBehaviour(MoveGenerator* moveGenerator, const double& posInicial, 
         const double& posObjetivo, const double& tolerancia, const bool& reconocerObjetos) :
      MoveBehaviour(moveGenerator), posInicial(posInicial), posActual(posInicial), posObjetivo(posObjetivo), 
         tolerancia(tolerancia), reconocerObjetos(reconocerObjetos)
    {
    }
    
    //Destructor
    BasicMoveBehaviour::~BasicMoveBehaviour()
    {
    }
    
    //Comprobar si ha terminado el objetivo
    bool BasicMoveBehaviour::checkIfEnded() 
    {
      return fabs(this->posObjetivo - this->posActual) < this->tolerancia;
    }
    
    //Reiniciar estado del comportamiento
    void BasicMoveBehaviour::restart()
    {
      //Llamada al método del padre
      MoveBehaviour::restart();
      //Reiniciar posición actual
      this->posActual = this->posInicial;
    }
    
    //Comprobar si debe realizarse el reconocimiento de objetos
    bool BasicMoveBehaviour::checkToRecognize()
    {
      return this->reconocerObjetos;
    }

    //Actualizar posición actual
    void BasicMoveBehaviour::updatePosition(const double& increment)
    {
      this->posActual += increment;
    }
}

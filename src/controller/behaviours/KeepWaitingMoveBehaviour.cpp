#include "KeepWaitingMoveBehaviour.h"
#include <cmath>
#include <algorithm>
#include <boost/thread/thread.hpp>

#define DEBUG

namespace var
{
    //Constructor
    KeepWaitingMoveBehaviour::KeepWaitingMoveBehaviour(MoveGenerator* moveGenerator, const int& iteraciones, 
         const double &millis, const bool& reconocerObjeto) :
      BasicMoveBehaviour(moveGenerator, 0, iteraciones, 0.001, reconocerObjeto), millis(millis)
    {
    }
    
    //Destructor
    KeepWaitingMoveBehaviour::~KeepWaitingMoveBehaviour()
    {
    }
    
    //Realizar movimiento
    bool KeepWaitingMoveBehaviour::move()
    {      
      #ifdef DEBUG
      std::cerr<<"Realizando espera de: "<<this->millis<<" ms\n";
      #endif
      
      //Esperar tiempo de movimiento
      boost::this_thread::sleep(boost::posix_time::milliseconds(this->millis)); 
      
      //Actualizar tiempo
      this->updatePosition(1);
      
      return true;         
    }
}

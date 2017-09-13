#include "NoPlanifiedMotionController.h"

#define DEBUG

namespace var
{
  //Constructor
  NoPlanifiedMotionController::NoPlanifiedMotionController(ros::NodeHandle& nh) : MotionController(nh),
      moveGenerator(nh)
  {
  }
    
  //Realizar movimiento
  bool NoPlanifiedMotionController::move()
  {
      //Mover base 
      #ifdef DEBUG
      std::cerr<<"Orden de movimiento del controlador"<<std::endl;
      #endif
      return this->moveBehaviour->execute(this->realizarReconocimiento);
  }
  
  //Parar el robot
  bool NoPlanifiedMotionController::stop()
  {
      return this->moveGenerator.stop(500);
  }   
         
  //Destructor
  NoPlanifiedMotionController::~NoPlanifiedMotionController()
  {
      //Borrado seguro
      if(this->moveBehaviour != NULL)
      {
         delete this->moveBehaviour;
         this->moveBehaviour = NULL;
      }
  }
}

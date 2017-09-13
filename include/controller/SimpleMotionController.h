#ifndef SIMPLE_MOTION_CONTROLLER_H
#define SIMPLE_MOTION_CONTROLLER_H

#include "NoPlanifiedMotionController.h"

namespace var
{
   //Controlador con reconocimiento sobre un objeto sin planificar
   class SimpleMotionController : public NoPlanifiedMotionController
   {
      public:
         //Constructor
         SimpleMotionController(ros::NodeHandle& nh);
         //Destructor
         virtual ~SimpleMotionController();
	      
	   protected:
	      //Construir el comportamiento del movimiento
	      virtual void constructMoveBehaviour();
   };
}

#endif

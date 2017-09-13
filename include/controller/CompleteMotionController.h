#ifndef COMPLETE_MOTION_CONTROLLER_H
#define COMPLETE_MOTION_CONTROLLER_H

#include "NoPlanifiedMotionController.h"

namespace var
{
   //Controlador con reconocimiento completo del entorno sin planificación
   class CompleteMotionController : public NoPlanifiedMotionController
   {
      public:
         //Constructor
         CompleteMotionController(ros::NodeHandle& nh);
         //Destructor
         virtual ~CompleteMotionController();
	      
	   protected:
	      //Construir el comportamiento del movimiento
	      virtual void constructMoveBehaviour();
   };
}

#endif

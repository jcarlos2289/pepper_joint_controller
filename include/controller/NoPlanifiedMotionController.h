#ifndef NO_PLANIFIED_MOTION_CONTROLLER_H
#define NO_PLANIFIED_MOTION_CONTROLLER_H

#include "MotionController.h"
#include "MoveGenerator.h"
#include "MoveBehaviour.h"

namespace var
{
   //Controlador sin planificar para el robot
   class NoPlanifiedMotionController : public MotionController
   {
      public:
         //Constructor
         NoPlanifiedMotionController(ros::NodeHandle& nh);
         //Destructor
         virtual ~NoPlanifiedMotionController();
         //Parar el robot
         virtual bool stop();
	      
	   protected:
	      //Construir el comportamiento del movimiento
	      virtual void constructMoveBehaviour() = 0;
	      //Realizar movimiento
	      virtual bool move() override;
	      
	      //Generador de movimiento
	      MoveGenerator moveGenerator;
	      //Comportamiento de movimiento
	      MoveBehaviour* moveBehaviour;
   };
}

#endif

#include "SimpleMotionController.h"
#include "SuccessionMoveBehaviour.h"
#include "HomePosition.h"
#include "LShoulderPitchBehaviour.h"
#include "RShoulderPitchBehaviour.h"
#include "HeadYawRightPosition.h"
#include "HeadYawBehaviour.h"
#include "HeadYawLeftPosition.h"
#include "HeadPitchDownPosition.h"
#include "HeadPitchBehaviour.h"
#include "HeadPitchTopPosition.h"
#include "KeepWaitingMoveBehaviour.h"

#define DEBUG

namespace var
{
  //Constructor
  SimpleMotionController::SimpleMotionController(ros::NodeHandle& nh) : NoPlanifiedMotionController(nh)
  {
      //Definición del comportamiento
      this->constructMoveBehaviour();
  }
           
  //Destructor
  SimpleMotionController::~SimpleMotionController()
  {
  }
  
  //Construir el comportamiento del movimiento
  void SimpleMotionController::constructMoveBehaviour()
  {
      //Sucesión de movimientos
      SuccessionMoveBehaviour* beh = new SuccessionMoveBehaviour(&moveGenerator);
      //Posición home del robot
      beh->addBehaviour(new HomePosition(&moveGenerator, 0.1, 6000, true));
      //Mover brazo izquierdo abajo
      beh->addBehaviour(new LShoulderPitchBehaviour(&moveGenerator, 0, 90, 90, 0.1, 5000, true));
      //Mover brazo derecho abajo
      beh->addBehaviour(new RShoulderPitchBehaviour(&moveGenerator, 0, 90, 90, 0.1, 5000, true));
      
		//Mover cabeza a la izquierda para inspeccionar
		beh->addBehaviour(new HeadYawBehaviour(&moveGenerator, 0, 60, 3, 0.1, 1200, true));
		//Espera por si se quedó en periodo de corte
		beh->addBehaviour(new KeepWaitingMoveBehaviour(&moveGenerator,3,1000,true));
		
		//Mover cabeza a la derecha para inspeccionar
		beh->addBehaviour(new HeadYawBehaviour(&moveGenerator, 0, -120, 3, 0.1, 1200, true));
		//Espera por si se quedó en periodo de corte
		beh->addBehaviour(new KeepWaitingMoveBehaviour(&moveGenerator,3,1000,true));
		
	   //Mover cabeza a la izquierda para centrarla
		beh->addBehaviour(new HeadYawBehaviour(&moveGenerator, 0, 60, 3, 0.1, 5000, true));
		//Espera por si se quedó en periodo de corte
		beh->addBehaviour(new KeepWaitingMoveBehaviour(&moveGenerator,3,1000,true));

		//Mover cabeza hacia arriba para inspeccionar
		beh->addBehaviour(new HeadPitchBehaviour(&moveGenerator, 0, -30, 2, 0.1, 1200, true));
		//Espera por si se quedó en periodo de corte
		beh->addBehaviour(new KeepWaitingMoveBehaviour(&moveGenerator,3,1000,true));
		//Mover cabeza hacia abajo para inspeccionar
		beh->addBehaviour(new HeadPitchBehaviour(&moveGenerator, 0, 60, 2, 0.1, 1200, true));
		//Espera por si se quedó en periodo de corte
		beh->addBehaviour(new KeepWaitingMoveBehaviour(&moveGenerator,3,1000,true));
		
		//Mover cabeza hacia arriba para centrarla
		beh->addBehaviour(new HeadPitchBehaviour(&moveGenerator, 0, -30, 2, 0.1, 1200, true));
		//Espera por si se quedó en periodo de corte
		beh->addBehaviour(new KeepWaitingMoveBehaviour(&moveGenerator,3,1000,true));
      
      //Añadir comportamiento
      this->moveBehaviour = beh;
  }
}

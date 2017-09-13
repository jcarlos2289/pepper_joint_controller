#ifndef MOTION_CONTROLLER_H
#define MOTION_CONTROLLER_H

#include <ros/ros.h>
#include "std_msgs/String.h"
//#include "practica2/VisionMessage.h"

namespace var
{
   //Controlador de movimiento
   class MotionController
   {
      public:
         //Constructor
         MotionController(ros::NodeHandle& nh);
         //Destructor
         virtual ~MotionController();
         
         //Callback de acción
	      void actionCallback(const std_msgs::String::ConstPtr& msg);
	      //Callback del sensor completo de visión
	      //void callbackVisionSensor(const practica2::VisionMessage::ConstPtr& msg);
	      //Realizar acciones
	      virtual bool execute();
	      //Parar robot
	      virtual bool stop() = 0;
	      
	   protected:
	      //Enviar comando de captura
	      virtual bool sendCaptureMessage();
	      //Realizar movimiento
	      virtual bool move() = 0;
	      //Realizar reconocimiento
	      bool realizarReconocimiento;
      
      private:
         //Suscriptor de orden de movimiento
	      ros::Subscriber actionSub;
	      //Publicador de mensaje para captura
	      ros::Publisher capturePublisher;
	      
	      //Subscriptor para los mensajes de visión
	      ros::Subscriber visionSub;
	      
	      //Recibida respuesta desde la cámara
	      bool respuestaCamara;
	      //Orden recibida
	      std::string ordenRecibida;
	      //Booleano de permiso para realizar el movimiento
	      bool realizarMovimiento;
   };
}

#endif

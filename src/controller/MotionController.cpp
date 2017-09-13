#include "MotionController.h"
#include "pepper_joint_controller/StringMessage.h"

namespace var
{
  //Constructor
  MotionController::MotionController(ros::NodeHandle& nh) : realizarReconocimiento(true), respuestaCamara(true)
  {
      //Inicializar receptor de acciones
	   this->actionSub = nh.subscribe("/master/control/action", 1, &MotionController::actionCallback, this);
	   //Publicador de mensaje de captura
	   this->capturePublisher = nh.advertise<pepper_joint_controller::StringMessage>("/master/control/capture", 1);
	   //Suscripción al mensaje de visión
	   //this->visionSub = nh.subscribe<practica2::VisionMessage>("/robot/camera/vision", 1, &MotionController::callbackVisionSensor, this);
  }
  
  //Callback para recibir mensaje de acción
   void MotionController::actionCallback(const std_msgs::String::ConstPtr& msg)
   {
      //Comprobar si se recibió respuesta de la cámara previamente
      if(this->respuestaCamara)
      {
	      this->ordenRecibida = msg->data;
	      this->realizarMovimiento = true;
	   }
   }
   
   //Obtener información del sensor de visión
  /* void MotionController::callbackVisionSensor(
		const practica2::VisionMessage::ConstPtr& msg) 
	{
      //Indicar que se ha recibido respuesta desde la cámara
      this->respuestaCamara = true;
   }*/
   
   //Enviar mensaje al esclavo
   bool MotionController::sendCaptureMessage()
   {
	   //Publicar mensaje al capturador
	   pepper_joint_controller::StringMessage msg;
	   
	   //Rellenar cabecera
	   msg.header.stamp = ros::Time::now();
	   
	   //Enviar mensaje de captura y avisar de reconocimiento o no de objetos
	   if(realizarReconocimiento)
	      msg.data = "GO_Y";
	   else
	      msg.data = "GO_N";
	   
	   //Enviar mensaje de captura
	   this->capturePublisher.publish(msg);
	   
	   //Actualizar valor de respuesta de la cámara
	   this->respuestaCamara = false;
	   
	   return true;
   }
      
   //Realizar movimiento
   bool MotionController::execute()
   {	
	   //Comprobar si se debe procesar
	   if(!realizarMovimiento)
	   {
         #ifdef DEBUG
		   //std::cerr<<"No se ha habilitado el movimiento"<<std::endl;
         #endif
		   return false;
	   }
	   
	   //Realizar movimiento
	   if(!move())
	   {
	      #ifdef DEBUG
		   std::cerr<<"No se ha realizado el movimiento correctamente"<<std::endl;
         #endif
		   return false;
	   }
	
	   //Realizar envío
	   if(!sendCaptureMessage())
	   {
   #ifdef DEBUG
		   std::cerr<<"No se pudo enviar el mensaje para habilitar la captura"<<std::endl;
   #endif
		   return false;
	   }
	
	   #ifdef DEBUG
		   std::cout<<"Envío de captura habilitada realizado"<<std::endl;
	   #endif
	   //Marcar para no enviar más datos
	   realizarMovimiento = false;
	
	   return true;
   }
         
  //Destructor
  MotionController::~MotionController()
  {
  }
}

#ifndef MOVE_GENERATOR_H
#define MOVE_GENERATOR_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <naoqi_bridge_msgs/JointAnglesWithSpeed.h>
#include "MoveJointMessageGenerator.h"
#include "MoveBaseMessageGenerator.h"

namespace var
{
   //Clase para generar el movimiento
   class MoveGenerator
   {
      public:
         //Constructor
         MoveGenerator(ros::NodeHandle& nh);
         //Destructor
         ~MoveGenerator();
          
	      //Girar la base x grados sobre el eje vertical
	      bool moveBase(const MoveBaseType& moveType, const double &speed, const int &millis);   
	      //Girar articulación determinada x grados
	      bool moveJoint(const PepperJoint& joint, const double &degrees, const int &millis, const double &speed, const bool& relative);
	      //Girar articulaciones determinadas x grados
	      bool moveJoints(const std::vector<PepperJoint> &joint, const std::vector<double> &degrees, const int &millis, const double &speed, const bool& relative);
	      
	      //Parar el movimiento del robot
	      bool stop(const int &millis);
               
      private:
               
         //Convertir de grados a radianes
         double degreesToRadians(const double& degrees);
      
         //Enviar mensaje de movimiento de base
	      bool sendBaseMsg();	  
	      //Enviar mensaje de movimiento de articulación
	      bool sendJointMsg();	
	      
	      //Generador de mensajes de movimiento de joint
	      MoveJointMessageGenerator jointMsgGenerator;
	      //Generador de mensajes de movimiento de base
	      MoveBaseMessageGenerator baseMsgGenerator;
         //Publicador del movimiento de la base
	      ros::Publisher basePublisher;
	      //Publicador del movimiento de la cabeza
	      ros::Publisher jointPublisher;
	      //Mensaje de movimiento de articulaciones
	      naoqi_bridge_msgs::JointAnglesWithSpeed jointMsg;
	      //Mensaje de movimiento
	      geometry_msgs::Twist baseMsg;
	      //Tiempo de espera del movimiento
	      int millis;
   };
}

#endif

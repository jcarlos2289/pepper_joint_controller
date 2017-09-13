#ifndef MOVE_BASE_MESSAGE_GENERATOR
#define MOVE_BASE_MESSAGE_GENERATOR

#include <geometry_msgs/Twist.h>
#include <vector>
#include "MoveBaseType.h"

namespace var
{   
   //Información del mensaje de base
   class MoveBaseMessageInfo
   {
      public:
      
      //Constructor
      MoveBaseMessageInfo(const MoveBaseType& moveType, const double &speed);
      //Destructor
      virtual ~MoveBaseMessageInfo();
      //Información del mensaje
      //Articulación
      MoveBaseType moveType;
      //Velocidad
      double speed;
      
   };
   
   //Clase para la generación de mensajes de movimiento de base
   class MoveBaseMessageGenerator
   {
      public:
         //Constructor
         MoveBaseMessageGenerator();
         //Destructor
         ~MoveBaseMessageGenerator();
         
         //Creador de mensajes únicos
         void createMessageSingle(geometry_msgs::Twist &moveMsg, const MoveBaseMessageInfo &info);
         //Creador de mensajes múltiples
         void createMessageMultiple(geometry_msgs::Twist &moveMsg, const std::vector<MoveBaseMessageInfo>& info);
         //Crear mensaje de parada
         void createStopMessage(geometry_msgs::Twist &moveMsg);
         
     private:
         //Convertir de grados a radianes
         double degreesToRadians(const double& degrees);
         //Procesar info de movimiento
         void processMoveInfo(geometry_msgs::Twist &moveMsg, const MoveBaseMessageInfo &info);
         //Setear velocidad lineal x
         void setLinearX(geometry_msgs::Twist &moveMsg, const double &meters);
         //Setear velocidad lineal y
         void setLinearY(geometry_msgs::Twist &moveMsg, const double &meters);
         //Setear velocidad angular
         void setAngularZ(geometry_msgs::Twist &moveMsg, const double &degrees);
   };
}

#endif

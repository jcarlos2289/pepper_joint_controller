#ifndef ABSOLUTE_JOINT_POSITION_H
#define ABSOLUTE_JOINT_POSITION_H

#include "MoveBehaviour.h"
#include "MoveJointMessageGenerator.h"

namespace var
{
   //Clase para definir un movimiento hacia una posición absoluta de articulación en una sola pasada
   class AbsoluteJointPosition : public MoveBehaviour
   {
      public:
         //Constructor para una única articulación
         AbsoluteJointPosition(MoveGenerator* moveGenerator, const PepperJoint& joint, const double& posObjetivo, 
            const double& speed, const double &millis, const bool& reconocerObjetos);
         //Constructor para múltiples articulaciones
         AbsoluteJointPosition(MoveGenerator* moveGenerator, const double& speed, const double &millis, 
         const bool& reconocerObjetos, const std::vector<PepperJoint> &joints = std::vector<PepperJoint>(), 
         const std::vector<double> &posObjetivo = std::vector<double>());
         //Añadir joint y posición
         void addJoint(const PepperJoint& joint, const double& objetivo);
         //Destructor
         virtual ~AbsoluteJointPosition();
         
      protected:
         //Gestionar movimiento
         virtual bool move();
         //Realizar movimiento a posición absoluta de una sola pasada
         virtual bool moveAbsoluteOneStep();
         //Comprobar si ha terminado el objetivo
         virtual bool checkIfEnded();
         //Comprobar si debe realizarse el reconocimiento de objetos
         virtual bool checkToRecognize();
         
         //Articulación a mover
         std::vector<PepperJoint> joints;
         //Posición objetivo
         std::vector<double> posObjetivo;
         //Reconocer objetos
         bool reconocerObjetos;
         //Velocidad de movimiento de articulación
         double speed;
         //Milisegundos de espera tras enviar la orden
         double millis;
         //Movimiento realizado
         bool done;
   };
}

#endif

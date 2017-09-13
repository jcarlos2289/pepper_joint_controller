#include <signal.h>
#include <ros/ros.h>
#include <string>
#include "MotionControllerFactory.h"
#include "MoveGenerator.h"
#include "PepperJoint.h"

//Controlador de movimiento
var::MotionController *controller;
var::MoveGenerator *mvGen;

//Handler de cierre de ejecución
void mySigintHandler(int sig)
{
 	//Parar el robot
	controller->stop();
	//Parar el nodo
   ros::shutdown();
}

//Main para recibir ordenes de movimiento y transmitirlas
int main(int argc, char** argv)
{
   //Tipo de controlador
   std::string type;

	//Arrancar nodo 
	ros::init(argc, argv, "motion_controller", ros::init_options::NoSigintHandler);
	ros::NodeHandle nh;
	
	//Obtener parámetros
	ros::NodeHandle private_node_handle("~");
	//Tipo de controlador
	private_node_handle.param<std::string>("type", type, "");
	
	//Informar de los valores de las variables
	std::cout<<"Controller type: "<<type<<std::endl;
	
	//Generar controlador
	var::MotionControllerFactory factory;
	controller = factory.generate(type, nh);
	mvGen = new var::MoveGenerator(nh);
	mvGen->moveJoint();
	
	//Comprobar si se ha generado
	if(controller == NULL)
	{
	   std::cerr<<"Error. El tipo de controlador "<<type<<" no existe"<<std::cerr;
	   return -1;
	}
	
	//Definir handler de señal de cierre
	signal(SIGINT, mySigintHandler);

	//Crear retardo
	ros::Rate rate(10);

	//Bucle de ejecución
	while (ros::ok()) {
		//Lanzar callbacks
		ros::spinOnce();
		//Realizar acciones
		controller->execute();
		//Espera del bucle
		rate.sleep();
	}
}


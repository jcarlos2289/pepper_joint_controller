macro(use_cxx11)
  if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
    endif ()
  else ()
    set (CMAKE_CXX_STANDARD 11)
  endif ()
endmacro(use_cxx11)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    MESSAGE( STATUS "OpenMP activated")
endif()

#use_cxx11()
cmake_minimum_required(VERSION 2.8.3)
project(pepper_joint_controller)

#find_package(Eigen3 REQUIRED)

#if(NOT EIGEN3_INCLUDE_DIRS)
 # set(EIGEN3_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR})
#endif()

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
	eigen_conversions
  pcl_conversions
  pcl_ros
  roscpp
  sensor_msgs
  image_transport
  cv_bridge
  message_generation
  std_msgs
  sensor_msgs
  geometry_msgs
  cmake_modules
  )
  
#Incluir dependencias de caffe
#find_package(Caffe)
#include_directories(${Caffe_INCLUDE_DIRS})
#add_definitions(${Caffe_DEFINITIONS})

find_package(Boost REQUIRED COMPONENTS system)
find_package(OpenCV REQUIRED)
#FIND_PACKAGE(VTK REQUIRED)
#INCLUDE(${VTK_USE_FILE})

##Mensajes
add_message_files(
  FILES
 # RecognizedObject.msg
 # ObjectsMessage.msg
 # VisionMessage.msg
  StringMessage.msg
  #PredictionMessage.msg
 # ClassifiedImageMessage.msg
  #SceneMessage.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  sensor_msgs
  geometry_msgs
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES get_pointclouds
#  CATKIN_DEPENDS pcl_conversions pcl_ros roscpp sensor_msgs
#  DEPENDS system_lib
 CATKIN_DEPENDS message_runtime eigen_conversions DEPENDS EIGEN3
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
#Includes
# include/registration/keypoints
# include/registration/normals
# include/registration/features
# include/registration/matching
# include/registration/ransac
# include/registration/transform
# include/registration/integration
# include/registration/filtering
# include/registration/cloud
# include/registration/icp
# include/visualization
# include/capture
# include/mapping
# include/classification
# include/recognition
# include/mapping
# include/integration
include/controller
include/controller/behaviours
include/controller/behaviours/positions
${catkin_INCLUDE_DIRS}
#${CAFFE_INCLUDEDIR}
${Eigen_INCLUDE_DIRS}
)

## Declare a C++ library
file(GLOB_RECURSE SRC_SOURCES 
# src/capture/*.cpp 
# src/classification/*.cpp 
# src/recognition/*.cpp 
# src/integration/*.cpp 
# src/mapping/*.cpp 
   src/controller/*.cpp
# src/registration/*.cpp
# src/visualization/*.cpp
)

#Crear librería del proyecto
add_library(pepper-controller ${SRC_SOURCES})

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(get_pointclouds ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
#add_executable(master-coordination src/coordinationMasterMain.cpp)
#add_executable(master-classification src/classificationMain.cpp)
#add_executable(master-recognition src/recognitionMain.cpp)
##add_executable(master-registration src/masterRegistrationMain.cpp)
#add_executable(master-capture-to-file src/captureCloudToFileMain.cpp)
#add_executable(slave-capture-to-file src/captureCloudPassiveMain.cpp)
#add_executable(slave-from-file src/slaveFromFileMain.cpp)
#add_executable(slave-from-camera src/slaveCameraDriverMain.cpp)
         add_executable(motion-controller src/motionControllerMain.cpp)
#add_executable(objects-visualizer src/objectsVisualizerMain.cpp)
#add_executable(scene-visualizer src/sceneVisualizerMain.cpp)
#add_executable(objects-scene-saver src/objectsSceneSaverMain.cpp)
#add_executable(objects-scene-publisher src/objectsScenePublisherMain.cpp)
#add_executable(object-detection-logger src/objectDetectionLoggerMain.cpp)

#Dependencias
# add_dependencies(practica2-utils practica2_generate_messages_cpp)
# add_dependencies(master-coordination practica2-utils)
# add_dependencies(master-classification practica2-utils)
# add_dependencies(master-recognition practica2-utils)
# add_dependencies(master-capture-to-file practica2-utils)
# add_dependencies(master-registration practica2-utils)
# add_dependencies(slave-capture-to-file practica2-utils)
# add_dependencies(slave-from-file practica2-utils)
# add_dependencies(slave-from-camera practica2-utils)
    #          add_dependencies(motion-controller pepper-controller)
# add_dependencies(objects-visualizer practica2-utils)
# add_dependencies(scene-visualizer practica2-utils)
# add_dependencies(objects-scene-saver practica2-utils)
# add_dependencies(objects-scene-publisher practica2-utils)
# add_dependencies(object-detection-logger practica2-utils)

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(get_pointclouds_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target
#link_directories(${CAFFE_LINK_LIBRARY})
# target_link_libraries(practica2-utils ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} ${CURSES_LIBRARIES}  ${Eigen_LIBRARIES} ${Caffe_LIBRARIES} glog)
# target_link_libraries(master-coordination ${catkin_LIBRARIES} libvtkCommon.so libvtkFiltering.so practica2-utils)
# target_link_libraries(master-classification ${catkin_LIBRARIES} libvtkCommon.so libvtkFiltering.so practica2-utils)
# target_link_libraries(master-recognition ${catkin_LIBRARIES} libvtkCommon.so libvtkFiltering.so practica2-utils)
# target_link_libraries(master-capture-to-file ${catkin_LIBRARIES} libvtkCommon.so libvtkFiltering.so practica2-utils)
# target_link_libraries(master-registration ${catkin_LIBRARIES} libvtkCommon.so libvtkFiltering.so practica2-utils)
  target_link_libraries(motion-controller ${catkin_LIBRARIES} ) # pepper-controller libvtkCommon.so libvtkFiltering.so practica2-utils
# target_link_libraries(slave-capture-to-file ${catkin_LIBRARIES} libvtkCommon.so libvtkFiltering.so practica2-utils)
# target_link_libraries(slave-from-file ${catkin_LIBRARIES} libvtkCommon.so libvtkFiltering.so practica2-utils)
# target_link_libraries(slave-from-camera ${catkin_LIBRARIES} libvtkCommon.so libvtkFiltering.so practica2-utils)
# target_link_libraries(objects-visualizer ${catkin_LIBRARIES} libvtkCommon.so libvtkFiltering.so practica2-utils)
# target_link_libraries(scene-visualizer ${catkin_LIBRARIES} libvtkCommon.so libvtkFiltering.so practica2-utils)
# target_link_libraries(objects-scene-saver ${catkin_LIBRARIES} libvtkCommon.so libvtkFiltering.so practica2-utils)
# target_link_libraries(objects-scene-publisher ${catkin_LIBRARIES} libvtkCommon.so libvtkFiltering.so practica2-utils)
# target_link_libraries(object-detection-logger ${catkin_LIBRARIES} libvtkCommon.so libvtkFiltering.so practica2-utils)

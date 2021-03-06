cmake_minimum_required(VERSION 3.0.2)
project(fkie_iop_manipulator_joint_position_sensor)

# we need C++11 enabled if compile with kinetic
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

find_package(catkin REQUIRED COMPONENTS
             fkie_iop_component
             fkie_iop_events
             fkie_iop_manipulator_specification_service
             moveit_core
             moveit_ros_planning
             roscpp
             sensor_msgs
)

find_package(Boost REQUIRED COMPONENTS system thread)

iop_init(COMPONENT_ID 0)

###################################
## catkin specific configuration ##
###################################
catkin_package(
    CATKIN_DEPENDS
        fkie_iop_component
        fkie_iop_events
        fkie_iop_manipulator_specification_service
        moveit_core
        moveit_ros_planning
        roscpp
        sensor_msgs
    DEPENDS Boost
)

###########
## Build ##
###########

## Specify additional locations of header files
iop_code_generator(
# IDLS: the service definition files located in fkie_iop_builder/jsidl
# OWN_IDLS: the service definition files located in PROJECT_DIR/jsidl
# OVERRIDES: files which override the generated files while build. The generated files are copied to the same location with .gen extension
# EXTERN_SERVICES: the generated folder name of a service which is used from other library. This folder must be deleted while build.
  IDLS
    urn.jaus.jss.core-v1.1/Events.xml
    urn.jaus.jss.core-v1.1/Transport.xml
    urn.jaus.jss.manipulator-v2.0/ManipulatorSpecificationService.xml
    urn.jaus.jss.manipulator-v2.0/ManipulatorJointPositionSensor.xml
  OWN_IDLS
  OVERRIDES
    include/urn_jaus_jss_manipulator_ManipulatorJointPositionSensor/ManipulatorJointPositionSensor_ReceiveFSM.h
     src/urn_jaus_jss_manipulator_ManipulatorJointPositionSensor/ManipulatorJointPositionSensor_ReceiveFSM.cpp
    src/main.cpp
  EXTERN_SERVICES
    urn_jaus_jss_core_Events
    urn_jaus_jss_core_Transport
    urn_jaus_jss_manipulator_ManipulatorSpecificationService
  GENERATED_SOURCES cppfiles
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${boost_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
            src/ManipulatorJointPositionSensorPlugin.cpp
            ${cppfiles}
)

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}
                      ${catkin_LIBRARIES}
)

install(
  DIRECTORY ${IOP_INSTALL_INCLUDE_DIRS} DESTINATION ${CATKIN_GLOBAL_INCLUDE_DESTINATION}
  PATTERN "*.old" EXCLUDE
  PATTERN "*.gen" EXCLUDE
)

install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark other files for installation (e.g. launch and bag files, etc.)
install(
   FILES ./plugin_iop.xml
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

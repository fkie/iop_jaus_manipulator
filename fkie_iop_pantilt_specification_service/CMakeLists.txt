cmake_minimum_required(VERSION 3.0.2)
project(fkie_iop_pantilt_specification_service)

# we need C++11 enabled if compile with kinetic
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
             fkie_iop_accesscontrol
             fkie_iop_component
             moveit_msgs
             roscpp
             sensor_msgs
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)
find_package(Boost REQUIRED COMPONENTS system thread)


iop_init(COMPONENT_ID 0)
iop_export_service(urn_jaus_jss_manipulator_PanTiltSpecificationService
                   urn_jaus_jss_manipulator_PanTiltMotionProfileService)

## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

catkin_package(
    INCLUDE_DIRS include/public
    LIBRARIES ${PROJECT_NAME}
    CATKIN_DEPENDS
        fkie_iop_accesscontrol
        fkie_iop_component
        moveit_msgs
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
    urn.jaus.jss.core-v1.1/AccessControl.xml
    urn.jaus.jss.core-v1.1/Events.xml
    urn.jaus.jss.core-v1.1/Transport.xml
    urn.jaus.jss.manipulator-v2.0/PanTiltMotionProfileService.xml
    urn.jaus.jss.manipulator-v2.0/PanTiltSpecificationService.xml
  OWN_IDLS
  OVERRIDES
    include/urn_jaus_jss_manipulator_PanTiltMotionProfileService/PanTiltMotionProfileService_ReceiveFSM.h
    include/urn_jaus_jss_manipulator_PanTiltSpecificationService/PanTiltSpecificationService_ReceiveFSM.h
    src/urn_jaus_jss_manipulator_PanTiltMotionProfileService/PanTiltMotionProfileService_ReceiveFSM.cpp
    src/urn_jaus_jss_manipulator_PanTiltSpecificationService/PanTiltSpecificationService_ReceiveFSM.cpp
    src/main.cpp
  EXTERN_SERVICES
    urn_jaus_jss_core_AccessControl
    urn_jaus_jss_core_Events
    urn_jaus_jss_core_Transport
  GENERATED_SOURCES cppfiles
)

include_directories(
    include/public
    ${catkin_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
            src/PanTiltMotionProfileServicePlugin.cpp
            src/PanTiltSpecificationServicePlugin.cpp
            src/PantiltCfgReader.cpp
            ${cppfiles}
)

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}
                      ${catkin_LIBRARIES}
                      ${IOP_LIBRARIES}
                      ${Boost_LIBRARIES}
)

#############
## Install ##
#############

install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(
  DIRECTORY ${IOP_INSTALL_INCLUDE_DIRS} DESTINATION ${CATKIN_GLOBAL_INCLUDE_DESTINATION}
  PATTERN "*.old" EXCLUDE
  PATTERN "*.gen" EXCLUDE
)

install(
  DIRECTORY include/public/${PROJECT_NAME} DESTINATION ${CATKIN_GLOBAL_INCLUDE_DESTINATION}
  PATTERN "*.old" EXCLUDE
  PATTERN "*.gen" EXCLUDE
)

## Mark other files for installation (e.g. launch and bag files, etc.)
install(
   FILES ./plugin_iop.xml
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)


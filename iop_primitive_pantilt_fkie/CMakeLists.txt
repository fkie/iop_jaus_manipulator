cmake_minimum_required(VERSION 2.8.3)
project(iop_primitive_pantilt_fkie)

# we need C++11 enabled if compile with kinetic
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

find_package(catkin REQUIRED COMPONENTS
                iop_management_fkie
                iop_pantilt_specification_service_fkie
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
        iop_management_fkie
        iop_pantilt_specification_service_fkie
        moveit_core
        sensor_msgs
    DEPENDS Boost
)

###########
## Build ##
###########

## Specify additional locations of header files
iop_code_generator(
# IDLS: the service definition files located in iop_builder_fkie/jsidl
# OWN_IDLS: the service definition files located in PROJECT_DIR/jsidl
# OVERRIDES: files which override the generated files while build. The generated files are copied to the same location with .gen extension
# EXTERN_SERVICES: the generated folder name of a service which is used from other library. This folder must be deleted while build.
  IDLS
    urn.jaus.jss.core-v1.1/AccessControl.xml
    urn.jaus.jss.core-v1.1/Events.xml
    urn.jaus.jss.core-v1.1/Management.xml
    urn.jaus.jss.core-v1.1/Transport.xml
    urn.jaus.jss.manipulator-v2.0/PanTiltSpecificationService.xml
    urn.jaus.jss.manipulator-v2.0/PrimitivePanTilt.xml
  OWN_IDLS
  OVERRIDES
    include/urn_jaus_jss_manipulator_PrimitivePanTilt/PrimitivePanTilt_ReceiveFSM.h
    src/urn_jaus_jss_manipulator_PrimitivePanTilt/PrimitivePanTilt_ReceiveFSM.cpp
    src/main.cpp
  EXTERN_SERVICES
    urn_jaus_jss_manipulator_PanTiltSpecificationService
    urn_jaus_jss_core_AccessControl
    urn_jaus_jss_core_Events
    urn_jaus_jss_core_Management
    urn_jaus_jss_core_Transport
  GENERATED_SOURCES cppfiles
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${boost_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
            src/PrimitivePanTiltPlugin.cpp
            ${cppfiles}
)

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}
                      ${catkin_LIBRARIES}
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


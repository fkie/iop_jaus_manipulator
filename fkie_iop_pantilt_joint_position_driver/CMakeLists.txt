cmake_minimum_required(VERSION 3.5)
project(fkie_iop_pantilt_joint_position_driver)


# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Wno-ignored-qualifiers)
endif()


find_package(ament_cmake REQUIRED)
find_package(fkie_iop_component REQUIRED)
find_package(fkie_iop_management REQUIRED)
find_package(fkie_iop_pantilt_specification_service REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(moveit_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)

###############
## setup IOP ##
###############
iop_init(COMPONENT_ID 0)
iop_export_service(urn_jaus_jss_manipulator_PanTiltJointPositionDriver
                   urn_jaus_jss_manipulator_PanTiltJointPositionSensor)

## Specify additional locations of header files
iop_code_generator(
# IDLS: the service definition files located in fkie_iop_builder/jsidl
# OWN_IDLS: the service definition files located in PROJECT_DIR/jsidl
# OVERRIDES: files which override the generated files while build. The generated files are copied to the same location with .gen extension
# EXTERN_SERVICES: the generated folder name of a service which is used from other library. This folder must be deleted while build.
  IDLS
    urn.jaus.jss.core-v1.1/AccessControl.xml
    urn.jaus.jss.core-v1.1/Events.xml
    urn.jaus.jss.core-v1.1/Management.xml
    urn.jaus.jss.core-v1.1/Transport.xml
    urn.jaus.jss.manipulator-v2.0/PanTiltJointPositionDriver.xml
    urn.jaus.jss.manipulator-v2.0/PanTiltJointPositionSensor.xml
    urn.jaus.jss.manipulator-v2.0/PanTiltMotionProfileService.xml
    urn.jaus.jss.manipulator-v2.0/PanTiltSpecificationService.xml
  OWN_IDLS
  OVERRIDES
    include/urn_jaus_jss_manipulator_PanTiltJointPositionDriver/PanTiltJointPositionDriver_ReceiveFSM.h
    include/urn_jaus_jss_manipulator_PanTiltJointPositionSensor/PanTiltJointPositionSensor_ReceiveFSM.h
    src/urn_jaus_jss_manipulator_PanTiltJointPositionDriver/PanTiltJointPositionDriver_ReceiveFSM.cpp
    src/urn_jaus_jss_manipulator_PanTiltJointPositionSensor/PanTiltJointPositionSensor_ReceiveFSM.cpp
  EXTERN_SERVICES
    urn_jaus_jss_core_AccessControl
    urn_jaus_jss_core_Events
    urn_jaus_jss_core_Management
    urn_jaus_jss_core_Transport
    urn_jaus_jss_manipulator_PanTiltMotionProfile
    urn_jaus_jss_manipulator_PanTiltSpecification
  GENERATED_SOURCES cppfiles
)

###########
## Build ##
###########
set(dependencies
  fkie_iop_component
  fkie_iop_management
  fkie_iop_pantilt_specification_service
  geometry_msgs
  moveit_msgs
  sensor_msgs
  std_msgs
  tf2
  tf2_ros
)

include_directories(
    include/public
    ${fkie_iop_management_INCLUDE_DIRS}
    ${fkie_iop_pantilt_specification_service_INCLUDE_DIRS}
    ${IOP_COMPONENT_INCLUDE_DIRS}
)
add_library(${PROJECT_NAME} SHARED
            ${cppfiles}
)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME} PUBLIC
  ${geometry_msgs_TARGETS}
  ${moveit_msgs_TARGETS}
  ${sensor_msgs_TARGETS}
  ${std_msgs_TARGETS}
  ${tf2_TARGETS}
  ${tf2_ros_TARGETS}
  fkie_iop_management::fkie_iop_management
  fkie_iop_pantilt_specification_service::fkie_iop_pantilt_specification_service
)


#############
## Install ##
#############

install(
  DIRECTORY ${IOP_INSTALL_INCLUDE_DIRS}
  DESTINATION include/${PROJECT_NAME}
  PATTERN "*.old" EXCLUDE
  PATTERN "*.gen" EXCLUDE
)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}Targets
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(
   DIRECTORY launch
   DESTINATION share/${PROJECT_NAME}
)

install(
  EXPORT ${PROJECT_NAME}Targets
  FILE ${PROJECT_NAME}Targets.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION share/${PROJECT_NAME}/cmake
)
ament_export_targets(${PROJECT_NAME}Targets HAS_LIBRARY_TARGET)

ament_export_include_directories(include ${IOP_COMPONENT_INCLUDE_DIRS} ${fkie_iop_management_INCLUDE_DIRS} ${fkie_iop_pantilt_specification_service_INCLUDE_DIRS})
ament_export_libraries(${PROJECT_NAME})
ament_export_dependencies(${dependencies})
pluginlib_export_plugin_description_file(fkie_iop_component plugin_iop.xml)

ament_package()


cmake_minimum_required(VERSION 2.8.3)
project(iop_manipulator_core_fkie)

# we need C++11 enabled if compile with kinetic
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x -Wfatal-errors -Wno-variadic-macros -Wno-unknown-pragmas")

find_package(catkin REQUIRED COMPONENTS
                eigen_conversions
                iop_builder_fkie
                moveit_core
                moveit_msgs
                moveit_ros_planning
                roscpp
                sensor_msgs
                )

find_package(Boost REQUIRED COMPONENTS system thread)

find_package(PkgConfig REQUIRED)
pkg_search_module(EIGEN3 REQUIRED eigen3)

iop_init(COMPONENT_ID 0)

###################################
## catkin specific configuration ##
###################################
catkin_package(
    INCLUDE_DIRS include ${EIGEN3_INCLUDE_DIRS}
    LIBRARIES ${PROJECT_NAME}
    CATKIN_DEPENDS
        eigen_conversions
        iop_builder_fkie
        moveit_core
        moveit_msgs
        moveit_ros_planning
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
  OWN_IDLS
  OVERRIDES
  EXTERN_SERVICES
  GENERATED_SOURCES cppfiles
)

add_definitions(${EIGEN3_DEFINITIONS})

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIRS}
    ${IOP_INCLUDE_DIRS}
)

## Specify libraries to link a library or executable target against
add_library(${PROJECT_NAME}
            src/ManipulatorUrdfReader.cpp
            src/PantiltCfgReader.cpp
            src/ReportManipulatorSpecifications.cpp
            src/ReportPanTiltMotionProfile.cpp
            src/ReportPanTiltSpecifications.cpp
           )
target_link_libraries(${PROJECT_NAME}
                      ${catkin_LIBRARIES}
                      ${IOP_LIBRARIES}
                      ${Boost_LIBRARIES}
                     )

# Mark executables and/or libraries for installation
install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(
  DIRECTORY include/${PROJECT_NAME} DESTINATION ${CATKIN_GLOBAL_INCLUDE_DESTINATION}
  PATTERN "*.old" EXCLUDE
  PATTERN "*.gen" EXCLUDE
)
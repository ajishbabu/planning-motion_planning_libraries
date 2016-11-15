set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")

rock_testsuite(motion_planning_libraries-test suite.cpp
   test_MotionPlanning.cpp
   test_SbplSplineMotionPrimitives.cpp
   DEPS motion_planning_libraries
   DEPS_PKGCONFIG ompl)

rock_executable( generate_mprim
    SOURCES generate_mprim.cpp
    DEPS motion_planning_libraries )

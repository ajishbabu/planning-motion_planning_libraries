#include <stdlib.h>
#include <stdio.h>

#include <motion_planning_libraries/MotionPlanningLibraries.hpp>
#include <motion_planning_libraries/Helpers.hpp>
#include <motion_planning_libraries/sbpl/SbplMotionPrimitives.hpp>

using namespace motion_planning_libraries;

int main( int argc, char* argv[] ) 
{
    struct MotionPrimitivesConfig config;
    config.mMobility.mSpeed = 0.3;
    config.mMobility.mTurningSpeed = 0.3;
    config.mMobility.mMinTurningRadius = 0.2;
    
    config.mMobility.mMultiplierForward = 1;
    config.mMobility.mMultiplierBackward = 2;
    config.mMobility.mMultiplierLateral = 0;
    config.mMobility.mMultiplierForwardTurn = 1;
    config.mMobility.mMultiplierBackwardTurn = 2;
    config.mMobility.mMultiplierPointTurn = 3;
    
    config.mNumPrimPartition = 4;
    config.mNumPosesPerPrim = 10;
    config.mNumAngles = 16;
    
    config.mGridSize = 0.1;
    
    SbplMotionPrimitives mprims(config);
    mprims.createPrimitives();
    mprims.storeToFile("output.mprim");

    return 0;
}

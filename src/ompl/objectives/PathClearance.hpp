#ifndef _OBJECTIVE_PATH_CLEARANCE_HPP_
#define _OBJECTIVE_PATH_CLEARANCE_HPP_

#include <stdio.h>

#include <vector>

#include <ompl/base/spaces/SE2StateSpace.h>
#include <ompl/base/objectives/StateCostIntegralObjective.h>

namespace motion_planning_libraries
{

class PathClearance :  public ompl::base::StateCostIntegralObjective {
    
 public:
    PathClearance(const ompl::base::SpaceInformationPtr& si) : 
            ompl::base::StateCostIntegralObjective(si, true) {
    }
    
    ompl::base::Cost stateCost(const ompl::base::State* s) const
    {
        double clearance = si_->getStateValidityChecker()->clearance(s);
        if(clearance != 0) {
            clearance = 1 / clearance;
        }
        
        return ompl::base::Cost(clearance);
    }
};

} // end namespace motion_planning_libraries

#endif

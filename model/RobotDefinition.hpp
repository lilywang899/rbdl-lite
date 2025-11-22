#ifndef ROBOT_DEFINITION
#define ROBOT_DEFINITION
#include <iostream>
using namespace std;
#if 0
namespace robot{
    constexpr int num_q = 19;
    constexpr int num_qdot = 18;
    constexpr int num_act_joint = 12;
    constexpr int num_virtual = 6;
};

namespace robot_link{
    constexpr int trunk = 0;
    constexpr int FR_foot = 2;
    constexpr int FL_foot = 1;
    constexpr int RR_foot = 4;
    constexpr int RL_foot = 3;
};
namespace robot_joint{
    constexpr int virtual_X = 0;
    constexpr int virtual_Y = 1;
    constexpr int virtual_Z = 2;
    constexpr int virtual_Rx = 3;
    constexpr int virtual_Ry = 4;
    constexpr int virtual_Rz = 5;

    constexpr int FL_hip_joint = 6;
    constexpr int FL_thigh_joint = 7;
    constexpr int FL_calf_joint = 8;
    
    constexpr int FR_hip_joint = 9;
    constexpr int FR_thigh_joint = 10;
    constexpr int FR_calf_joint = 11;
    
    constexpr int RL_hip_joint = 12;
    constexpr int RL_thigh_joint = 13;
    constexpr int RL_calf_joint = 14;
    
    constexpr int RR_hip_joint = 15;
    constexpr int RR_thigh_joint = 16;
    constexpr int RR_calf_joint = 17;
      
    constexpr int virtual_Rw = 18;
};
extern const char* link_name[];

#else

namespace robot {
constexpr int num_q = 13;
constexpr int num_qdot = 12;
constexpr int num_act_joint = 6;
constexpr int num_virtual = 6;
};// namespace robot

namespace robot_link {
constexpr int trunk = 0;
constexpr int link1_1_1 = 1;
constexpr int link2_1_1 = 2;
constexpr int link3_1_1 = 3;
constexpr int link4_1_1 = 4;
constexpr int link5_1_1 = 5;
constexpr int link6_1_1 = 6;
};// namespace robot_link
namespace robot_joint {
constexpr int virtual_X = 0;
constexpr int virtual_Y = 1;
constexpr int virtual_Z = 2;
constexpr int virtual_Rx = 3;
constexpr int virtual_Ry = 4;
constexpr int virtual_Rz = 5;

constexpr int link1_1_1 = 6;
constexpr int link2_1_1 = 7;
constexpr int link3_1_1 = 8;
constexpr int link4_1_1 = 9;
constexpr int link5_1_1 = 10;
constexpr int link6_1_1 = 11;

constexpr int virtual_Rw = 12;
};// namespace robot_joint
extern const char *link_name[];

#endif
#endif

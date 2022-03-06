#ifndef Level_h
#define Level_h

enum orientation
{
    horizontal = 0,
    vertical = 1
};

class Level
{
    public:
        Level();

        void update(double acc_x, double acc_y, double acc_z);
        double getAngle();
    
    private:
        double acc_x, acc_y, acc_z; // stores acceleration values
        double pitch, roll, yaw; // computed angles based on current orientation
        orientation orientation; // device orientation
};

#endif
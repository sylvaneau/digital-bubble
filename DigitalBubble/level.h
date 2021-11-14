#ifndef Level_h
#define Level_h

class Level
{
    public:
        Level();

        void update(double acc_x, double acc_y, double acc_z);
        double getAngle();
    
    private:
        double acc_x, acc_y, acc_z;
        double pitch, roll;
};

#endif
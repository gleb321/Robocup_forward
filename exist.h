#ifndef EXIST
#define EXIST

#include <Arduino.h>
#include <Pixy2.h>

struct camera {
        int x;
        int y;
        int width;
        int height;
        double angle;
        double distance;
        double square;
        bool found;
};

class Math {
    private:
            const double central_x = 164;
            const double central_y = 115;
            const double front_x = 175; 
            const double front_y = 116; 
    public:
            int sign(double x);
            double radian(double angle); 
            double distance(int x, int y);
            double countDistance(double d);
            double countAngle(double ball_x, double ball_y);
};

class Robot {
    private:
            const byte left_button_port = 23;
            const byte right_button_port = 22;
            const byte motors_in1[4] = {38, 42, 28, 3};
            const byte motors_in2[4] = {36, 40, 30, 5};
            const byte motors_pwm[4] = {6, 44, 10, 12};
        const byte led_digital_port[3] = {33, 35, 37};
        int calibration_value[24] = {567, 596, 579, 588, 570, 539, 613, 677, 613, 624, 520, 620, 624, 586, 536, 584, 650, 629, 530, 635, 520, 523, 503, 546};
            const double angle_coef = 0.785398163397448;
    public:
            int degree;
        Pixy2 pixy;
        double led_angle[24];
        bool led_value[24];
    public:
            void init();
        void updateGyro();
            bool buttonPressed(byte n);
            int readChannel(int n, int m);
            bool updateLed(bool led_value[]);
            void runMotor(byte port, short speed);
        bool setTimer(long long timer, int dt);
        int updateCamera(int signature[], int n);
            void moveAngle(double angle, short speed, int u);
};

#endif
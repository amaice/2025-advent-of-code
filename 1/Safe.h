//
// Created by amaic on 12/1/2025.
//

#ifndef SAFE_H
#define SAFE_H



class Safe {
    public:
        int pos;
        int times_on_zero;

        Safe() {
            pos = 50;
            times_on_zero = 0;
        }
        void turn(char direction, int distance);
        int password();
};

#endif //SAFE_H

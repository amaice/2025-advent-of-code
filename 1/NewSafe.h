#ifndef NEWSAFE_H
#define NEWSAFE_H

class NewSafe {
    public:
        int pos;
        int times_on_zero;

        NewSafe() {
            pos = 50;
            times_on_zero = 0;
        }
        void turn(char direction, int distance);
        int password() const;
};

#endif //NEWSAFE_H

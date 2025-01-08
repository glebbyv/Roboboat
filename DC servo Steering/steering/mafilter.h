#ifndef MAFILTER_H
#define MAFILTER_H

class Filter {
private:
    float alpha;      // Smoothing factor (0 < alpha ≤ 1)
    float prev_value; // Previous filtered value

public:
    // Constructor
    Filter(float alpha);

    // Filter function
    float filter(float input);
};

#endif // RECURSIVE_FILTER_H
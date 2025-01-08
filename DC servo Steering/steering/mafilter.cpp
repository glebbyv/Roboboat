#include "mafilter.h"

// Constructor
Filter::Filter(float alpha) : alpha(alpha), prev_value(0) {}

// Filter function
float Filter::filter(float input) {
    prev_value = alpha * input + (1 - alpha) * prev_value;
    return prev_value;
}
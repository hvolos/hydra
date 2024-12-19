#ifndef FAULT_H
#define FAULT_H

enum fault_method {
    FAULT_NONE = 0,
    FAULT_EINJ,
    FAULT_SPIN
};

extern int fault_latency_us;
extern enum fault_method fault_method;

// Function to inject synthetic fault
void inject_fault();

#endif // FAULT_H

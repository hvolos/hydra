#include "fault.h"
#include "util.h"

enum fault_method fault_method = FAULT_NONE;
int fault_latency_us = 30;


static void inject_fault_einj();

void inject_fault()
{
    if (fault_method == FAULT_EINJ) {
        inject_fault_einj();
    } else if (fault_method == FAULT_SPIN) {
      spin_microseconds(fault_latency_us);
    }
}

void inject_fault_einj()
{
    echo("/sys/kernel/debug/apei/einj/param1", "0x%x", 0x12345000);
    echo("/sys/kernel/debug/apei/einj/param2", "0x%lx", 0xfffffffffffff000);
    echo("/sys/kernel/debug/apei/einj/error_type", "0x%x", 0x8);
    echo("/sys/kernel/debug/apei/einj/error_inject", "%d", 1);
}

#ifndef TOPOLOGY_API_DEVICE_H
#define TOPOLOGY_API_DEVICE_H

struct Value;

class Device {
private:
    Value* value;

public:
    explicit Device(int defaultValue=0, int min=0, int max=0);

    int getMin();
    int getMax();
    int getDefault();
};

#endif //TOPOLOGY_API_DEVICE_H

#ifndef TOPOLOGY_API_DEVICE_H
#define TOPOLOGY_API_DEVICE_H

#include "ElectronicObject.h"
#include "Node.h"

struct Value;
struct NetList;

class JsonExportVisitor;

class Device : public ElectronicObject{
private:
    Value* value;
protected:
    NetList* netlist;

public:
    explicit Device(double defaultValue=0, double min=0, double max=0);

    virtual ~Device();

    double getMin();
    double getMax();
    double getDefault();
    virtual bool isAttached(Node* ) = 0;
    virtual std::string accept(JsonExportVisitor* visitor) = 0;
};

#endif //TOPOLOGY_API_DEVICE_H

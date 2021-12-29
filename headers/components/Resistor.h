#ifndef TOPOLOGY_API_RESISTOR_H
#define TOPOLOGY_API_RESISTOR_H

#include "Device.h"
#include "Node.h"

#define DEFAULT_RES_VALUE 100
#define DEFAULT_MIN_RES_VALUE 10
#define DEFAULT_MAX_RES_VALUE 1000

class Resistor : public Device{
public:
    explicit Resistor(double defaultValue=DEFAULT_RES_VALUE,
                      double min=DEFAULT_MIN_RES_VALUE, double max=DEFAULT_MAX_RES_VALUE);

    ~Resistor() override;

    void attachT1(Node* t1);
    void attachT2(Node* t2);
    bool isAttached(Node *node) override;
    Node* getT1();
    Node* getT2();

    std::string accept(JsonExportVisitor *visitor) override;
};


#endif //TOPOLOGY_API_RESISTOR_H

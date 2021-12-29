#ifndef TOPOLOGY_API_CMOS_H
#define TOPOLOGY_API_CMOS_H

#include "Device.h"
#include "Node.h"

#define DEFAULT_CMOS_VALUE 1.5
#define DEFAULT_MIN_CMOS_VALUE 1
#define DEFAULT_MAX_CMOS_VALUE 2

class Cmos : public Device{
public:
    explicit Cmos(double defaultValue=DEFAULT_CMOS_VALUE,
                  double min=DEFAULT_MIN_CMOS_VALUE, double max=DEFAULT_MAX_CMOS_VALUE);

    ~Cmos() override;

    void attachDrain(Node* );
    void attachGate(Node* );
    void attachSource(Node* );
    bool isAttached(Node *node) override;
    Node* getSource();
    Node* getDrain();
    Node* getGate();
};


#endif //TOPOLOGY_API_CMOS_H

#ifndef TOPOLOGY_API_INDUCTOR_H
#define TOPOLOGY_API_INDUCTOR_H

#include "Device.h"

#define DEFAULT_IND_VALUE 100
#define DEFAULT_MIN_IND_VALUE 10
#define DEFAULT_MAX_IND_VALUE 1000

class Inductor : public Device{
public:
    explicit Inductor(double defaultValue=DEFAULT_IND_VALUE,
                      double min=DEFAULT_MIN_IND_VALUE, double max=DEFAULT_MAX_IND_VALUE);

    void attachT1(Node* );
    void attachT2(Node* );
    bool isAttached(Node *node) override;
};


#endif //TOPOLOGY_API_INDUCTOR_H

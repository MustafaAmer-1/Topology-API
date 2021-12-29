#ifndef TOPOLOGY_API_CAPACITOR_H
#define TOPOLOGY_API_CAPACITOR_H

#include "Device.h"
#include "Node.h"

#define DEFAULT_CAP_VALUE 100
#define DEFAULT_MIN_CAP_VALUE 10
#define DEFAULT_MAX_CAP_VALUE 1000

class Capacitor : public Device{
public:
    explicit Capacitor(double defaultValue=DEFAULT_CAP_VALUE,
                       double min=DEFAULT_MIN_CAP_VALUE, double max=DEFAULT_MAX_CAP_VALUE);

    ~Capacitor() override;

    void attachPos_t(Node* );
    void attachNeg_t(Node* );
    bool isAttached(Node *node) override;
    Node* getPos_t();
    Node* getNeg_t();

    std::string accept(JsonExportVisitor *visitor) override;
};


#endif //TOPOLOGY_API_CAPACITOR_H

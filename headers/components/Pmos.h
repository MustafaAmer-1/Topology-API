#ifndef TOPOLOGY_API_PMOS_H
#define TOPOLOGY_API_PMOS_H

#include "Cmos.h"

class Pmos : public Cmos{
public:
    explicit Pmos(double defaultValue=DEFAULT_CMOS_VALUE,
                  double min=DEFAULT_MIN_CMOS_VALUE, double max=DEFAULT_MAX_CMOS_VALUE);

    std::string accept(JsonExportVisitor *visitor) override;
};


#endif //TOPOLOGY_API_PMOS_H

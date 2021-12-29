#ifndef TOPOLOGY_API_NMOS_H
#define TOPOLOGY_API_NMOS_H

#include "Cmos.h"

class Nmos : public Cmos{
public:
    explicit Nmos(double defaultValue=DEFAULT_CMOS_VALUE,
                  double min=DEFAULT_MIN_CMOS_VALUE, double max=DEFAULT_MAX_CMOS_VALUE);

    std::string accept(JsonExportVisitor *visitor) override;
};


#endif //TOPOLOGY_API_NMOS_H

#ifndef TOPOLOGY_API_PMOS_H
#define TOPOLOGY_API_PMOS_H

#include "Cmos.h"

class Pmos : public Cmos{
public:
    std::string accept(JsonExportVisitor *visitor) override;
};


#endif //TOPOLOGY_API_PMOS_H

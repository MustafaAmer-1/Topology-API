#ifndef TOPOLOGY_API_NMOS_H
#define TOPOLOGY_API_NMOS_H

#include "Cmos.h"

class Nmos : public Cmos{
public:
    std::string accept(JsonExportVisitor *visitor) override;
};


#endif //TOPOLOGY_API_NMOS_H

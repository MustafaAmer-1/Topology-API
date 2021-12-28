#include "Pmos.h"
#include"JsonExportVisitor.h"

std::string Pmos::accept(JsonExportVisitor *visitor) {
    return visitor->exportPmos(this);
}

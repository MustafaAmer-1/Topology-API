#include "Pmos.h"
#include"JsonExportVisitor.h"

std::string Pmos::accept(JsonExportVisitor *visitor) {
    return visitor->exportPmos(this);
}

Pmos::Pmos(double defaultValue, double min, double max) : Cmos(defaultValue, min, max) {}

#include "Nmos.h"
#include "JsonExportVisitor.h"

std::string Nmos::accept(JsonExportVisitor *visitor) {
    return visitor->exportNmos(this);
}

Nmos::Nmos(double defaultValue, double min, double max) : Cmos(defaultValue, min, max) {}

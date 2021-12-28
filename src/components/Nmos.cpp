#include "Nmos.h"
#include "JsonExportVisitor.h"

std::string Nmos::accept(JsonExportVisitor *visitor) {
    return visitor->exportNmos(this);
}

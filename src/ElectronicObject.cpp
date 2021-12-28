#include "ElectronicObject.h"

ElectronicObject::ElectronicObject() {
    int i = 0;
    while(objects_map.find(std::to_string(i)) != objects_map.end()) i++;
    this->id = std::to_string(i);
    objects_map.insert({this->id, this});
}

const std::string &ElectronicObject::getId() const {
    return this->id;
}

void ElectronicObject::setId(const std::string &input_id) {
    if(objects_map.find(input_id) == objects_map.end()){
        objects_map.erase(this->id);
        objects_map.insert({input_id, this});
        this->id = input_id;
    }
    else throw IdException("This is used id");
}

ElectronicObject* ElectronicObject::getElementWithID(const std::string& input_id) {
    if(objects_map.find(input_id) != objects_map.end()) return objects_map[input_id];
    else throw IdException("No element exists with this ID");
}

IdException::IdException(const char * msg) {
    this->msg = msg;
}

const char *IdException::what() const noexcept {
    return this->msg;
}

#ifndef TOPOLOGY_API_ELECTRONICOBJECT_H
#define TOPOLOGY_API_ELECTRONICOBJECT_H

#include <string>
#include <map>
#include "IdException.h"

template<class T>
class ElectronicObject {
private:
    inline static std::map<std::string, T *> objects_map;
    std::string id;

protected:
    ElectronicObject() {
        int i = 0;
        while (objects_map.find(std::to_string(i)) != objects_map.end()) i++;
        this->id = std::to_string(i);
        objects_map.insert({this->id, (T *) this});
    }

    virtual ~ElectronicObject() {
        objects_map.erase(id);
    }

public:
    [[nodiscard]] const std::string &getId() const {
        return this->id;
    }

    void setId(const std::string &input_id) {
        if (objects_map.find(input_id) == objects_map.end()) {
            objects_map.erase(this->id);
            objects_map.insert({input_id, (T *) this});
            this->id = input_id;
        } else throw IdException("This is used id");
    }

    static T *getElementWithID(const std::string &input_id) {
        if (objects_map.find(input_id) != objects_map.end()) return objects_map[input_id];
        return nullptr;
    }

    static std::map<std::string, T *> getElementList(){
        return objects_map;
    }

};

#endif //TOPOLOGY_API_ELECTRONICOBJECT_H

/**
 * @file ElectronicObject.h
 * @author Mustafa Amer (eng.MustafaAmer0@gmail.com)
 * @brief ElectronicObject template class implementation.
 * @version 0.1
 * @date 2022-01-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TOPOLOGY_API_ELECTRONICOBJECT_H
#define TOPOLOGY_API_ELECTRONICOBJECT_H

#include <string>
#include <map>
#include "IdException.h"

/**
 * @brief template abstract base class for any class that has id
 * 
 * @tparam T delivered class that inherits from this class
 */
template<class T>
class ElectronicObject {
private:
    /**
     * @brief maps any constructed objects by thier id
     * 
     */
    inline static std::map<std::string, T *> objects_map;
    std::string id;

protected:
    /**
     * @brief Construct a new ElectronicObject object with a unique id
     * 
     */
    ElectronicObject() {
        int i = 0;
        while (objects_map.find(std::to_string(i)) != objects_map.end()) i++;
        this->id = std::to_string(i);
        objects_map.insert({this->id, (T *) this});
    }

    /**
     * @brief Destroy the ElectronicObject object and remove it from the static map
     * 
     */
    virtual ~ElectronicObject() {
        objects_map.erase(id);
    }

public:
    /**
     * @brief Get the id of an object
     * 
     * @return const std::string& id
     */
    [[nodiscard]] const std::string &getId() const {
        return this->id;
    }

    /**
     * @brief Set the id of an object and throws IdException there exist object with the given id
     * 
     * @param input_id - the id you want the object to be set to 
     */
    void setId(const std::string &input_id) {
        if (objects_map.find(input_id) == objects_map.end()) {
            objects_map.erase(this->id);
            objects_map.insert({input_id, (T *) this});
            this->id = input_id;
        } else throw IdException("This is used id");
    }

    /**
     * @brief Get the Element With the given id
     * 
     * @param input_id - element id
     * @return T* - object pointer of the base class type
     */
    static T *getElementWithID(const std::string &input_id) {
        if (objects_map.find(input_id) != objects_map.end()) return objects_map[input_id];
        return nullptr;
    }

    /**
     * @brief Get all constructed elements of the base class type
     * 
     * @return std::map<std::string, T *> maps id to object pointer
     */
    static std::map<std::string, T *> getElementList(){
        return objects_map;
    }

};

#endif //TOPOLOGY_API_ELECTRONICOBJECT_H

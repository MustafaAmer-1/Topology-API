#ifndef TOPOLOGY_API_ELECTRONICOBJECT_H
#define TOPOLOGY_API_ELECTRONICOBJECT_H

#include <string>
#include <map>

class ElectronicObject {
private:
    inline static std::map<std::string, ElectronicObject*> objects_map;
    std::string id;

protected:
    ElectronicObject();

public:
    const std::string &getId() const;
    void setId(const std::string &id);
    static ElectronicObject* getElementWithID(const std::string& input_id);
};

class IdException : public std::exception {
private:
    const char * msg;
public:
    explicit IdException(const char * msg);
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
};

#endif //TOPOLOGY_API_ELECTRONICOBJECT_H

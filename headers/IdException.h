#ifndef TOPOLOGY_API_IDEXCEPTION_H
#define TOPOLOGY_API_IDEXCEPTION_H

#include <exception>

class IdException : public std::exception {
private:
    const char * msg;
public:
    explicit IdException(const char * msg){
        this->msg = msg;
    }
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return this->msg;
    }
};

#endif //TOPOLOGY_API_IDEXCEPTION_H

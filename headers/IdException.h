/**
 * @file IdException.h
 * @author Mustafa Amer (eng.MustafaAmer0@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TOPOLOGY_API_IDEXCEPTION_H
#define TOPOLOGY_API_IDEXCEPTION_H

#include <exception>

/**
 * @brief defined class exception to report any objects id issues.
 * 
 */
class IdException : public std::exception {
private:
    const char * msg;
public:
    /**
     * @brief Construct a new Id Exception object with the given message
     * 
     * @param msg - reported message
     */
    explicit IdException(const char * msg){
        this->msg = msg;
    }
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return this->msg;
    }
};

#endif //TOPOLOGY_API_IDEXCEPTION_H

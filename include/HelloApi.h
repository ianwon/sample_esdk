#ifndef __HELLO_API_H
#define __HELLO_API_H

#include <string>

namespace apis::hello {

class HelloApi {
 public:
    HelloApi() = default;
    ~HelloApi() = default;

    std::string getHello();

 private:
};

}   // namespace apis::hello

#endif // __HELLO_API_H
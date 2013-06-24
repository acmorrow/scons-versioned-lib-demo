#include "foo.hpp"

#include <ostream>

namespace foo {

    void say_hello(std::ostream& stream) {
        stream << "Hello, World!!\n";
    }

} // namespace foo

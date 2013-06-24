#include "goodbye.hpp"

#include <ostream>

namespace foo {

    void say_goodbye(std::ostream& stream) {
        stream << "Goodbye, World!\n";
    }

} // namespace foo

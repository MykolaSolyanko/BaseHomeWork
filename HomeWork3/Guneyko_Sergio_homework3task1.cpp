#include <iostream>
#include <memory>

class debug {
  public:
    debug() {
        std::cout << "debug" << std::endl;
    }

    ~debug() {
        std::cout << "~debug" << std::endl;
    }

};

debug* getDebug() {
    auto temp = std::make_unique<debug>();

    return temp.get();
}

int main(int argc, char const *argv[]) {
    auto test = getDebug();
    std::cout << "test\n";
    return 0;
}

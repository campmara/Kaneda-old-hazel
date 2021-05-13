#include <Kaneda.h>

class Sandbox : public Kaneda::Application {
public:
    Sandbox() {

    }

    ~Sandbox() {

    }
};

Kaneda::Application *Kaneda::CreateApplication() {
    return new Sandbox();
}
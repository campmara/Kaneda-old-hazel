#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H

#ifdef K_PLATFORM_WINDOWS

extern Kaneda::Application *Kaneda::CreateApplication();

int main(int argc, char** argv) {
    Kaneda::Log::Init();
    K_CORE_WARN("Initialized Log!");

    int a = 5;
    K_INFO("Hello! Var = {0}", a);

    auto app = Kaneda::CreateApplication();
    app->Run();
    delete app;
    app = nullptr;

    return 0;
}
#endif

#endif
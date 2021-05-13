#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H

#ifdef K_PLATFORM_WINDOWS

extern Kaneda::Application *Kaneda::CreateApplication();

int main() {
    printf("Kaneda Engine ~~~~~~~~~~~~~~~~\n");
    auto app = Kaneda::CreateApplication();
    app->Run();
    delete app;
    app = nullptr;

    return 0;
}
#endif

#endif
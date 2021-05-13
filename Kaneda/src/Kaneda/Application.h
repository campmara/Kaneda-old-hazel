#ifndef APPLICATION_H
#define APPLCIATION_H

#include "Core.h"

namespace Kaneda {
    class KANEDA_API Application {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // To be defined in the client.
    Application *CreateApplication();
}

#endif
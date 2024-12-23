#pragma once

#include <vector>
#include "framework/core/System.h"

namespace Phantom
{
    class FrameworkCore
    {
    public:
        FrameworkCore();
        ~FrameworkCore();

        void Register(System* sys);
        void RunGameLoop();

    private:
        std::vector<System*> m_systems;
        bool m_alive;
    };
}

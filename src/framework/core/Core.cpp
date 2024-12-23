#include <chrono>
#include "framework/core/Core.h"

namespace Phantom
{
    FrameworkCore::FrameworkCore() :
        m_alive(true)
    {

    }

    FrameworkCore::~FrameworkCore()
    {
        for (auto rit = m_systems.rbegin(); rit != m_systems.rend(); ++rit)
        {
            (*rit)->Uninit();
        }
    }

    void FrameworkCore::Register(System* sys)
    {
        m_systems.push_back(sys);
        sys->Init();
    }

    void FrameworkCore::RunGameLoop()
    {
        auto prev = std::chrono::high_resolution_clock::now();
        while (m_alive)
        {
            auto curr = std::chrono::high_resolution_clock::now();
            auto dt = std::chrono::duration_cast<std::chrono::seconds>(curr - prev);
            for (auto it = m_systems.begin(); it != m_systems.end(); ++it)
            {
                (*it)->Update(dt.count());
            }
            prev = std::chrono::high_resolution_clock::now();
        }
    }
}

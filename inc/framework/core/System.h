#pragma once

namespace Phantom
{
    class System
    {
    public:
        virtual ~System() {}

        virtual void Init() {}
        virtual void Update(float) {}
        virtual void Uninit() {}
    };
}

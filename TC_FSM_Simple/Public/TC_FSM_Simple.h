#pragma once

#include "Modules/ModuleManager.h"

class FTC_FSM_SimpleModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};

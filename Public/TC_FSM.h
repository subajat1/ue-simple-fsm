#pragma once

#include "Modules/ModuleManager.h"

class FTC_FSMModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

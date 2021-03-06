#pragma once

#include "settings/ScraperSettings.h"

#include <QString>

class ScraperInterface
{
public:
    virtual QString name() const = 0;
    virtual QString identifier() const = 0;
    virtual bool hasSettings() const = 0;
    virtual void loadSettings(const ScraperSettings& settings) = 0;
    virtual void saveSettings(ScraperSettings& settings) = 0;
    virtual ~ScraperInterface() = default;
};

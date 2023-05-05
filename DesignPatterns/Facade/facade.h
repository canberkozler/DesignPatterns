#pragma once

#include "../AbstractFactory/armor.h"

class ArmorBuilderFacade
{
public:
    ArmorBuilderFacade()
    {
        heavyarmor_ = new HeavyArmor();
        mediumarmor_ = new MediumArmor();
        lightarmor_ = new LightArmor();
    }

    ~ArmorBuilderFacade()
    {
        delete heavyarmor_;
        delete mediumarmor_;
        delete lightarmor_;
    }

    std::string getHeavyArmor() const { return heavyarmor_->ArmorType; }
    std::string getMediumArmor() const { return mediumarmor_->ArmorType; }
    std::string getLightArmor() const { return lightarmor_->ArmorType; }

private:
    HeavyArmor* heavyarmor_;
    MediumArmor* mediumarmor_;
    LightArmor* lightarmor_;
};
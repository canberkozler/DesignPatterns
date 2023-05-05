#pragma once
#include <string>

class Item {
public:
    virtual ~Item() = default;
    virtual std::string getName() const = 0;
    virtual void setName(const std::string& new_name) { name = new_name; }
protected:
    Item(std::string n) : name(n) {}
    Item() = default;
    std::string name;
};

class ConcreteWeapon : public Item {
public:
    ConcreteWeapon(std::string n, int d) : Item(n), damage(d) {}
    ConcreteWeapon(const ConcreteWeapon&) = delete;
    ConcreteWeapon(ConcreteWeapon&&) = delete;

    std::string getName() const override { return name; }
    int getDamage() const { return damage; }
protected:
    int damage;
};

class ConcreteArmor : public Item {
public:
    ConcreteArmor(std::string n, int dr) : Item(n), damage_res(dr) {}
    ConcreteArmor(const ConcreteArmor&) = delete;
    ConcreteArmor(ConcreteArmor&&) = delete;

    std::string getName() const override { return name; }
    int getDamageRes() const { return damage_res; }
protected:
    int damage_res;
};

enum ITEMTYPE { UNKNOWN, ARMOR, WEAPON };
ITEMTYPE WhatIsItemType(Item* item) {
    if (auto* the_cast_to_armor = dynamic_cast<ConcreteArmor*>(item);  the_cast_to_armor) {
        return ITEMTYPE::ARMOR;
    } else if (auto* the_cast_to_weapon = dynamic_cast<ConcreteArmor*>(item); the_cast_to_weapon) {
        return ITEMTYPE::WEAPON;
    } else return ITEMTYPE::UNKNOWN;
}

std::string WhatIsItemTypeString(Item* item) {
    if (auto* the_cast_to_armor = dynamic_cast<ConcreteArmor*>(item); the_cast_to_armor) {
        return "Armor";
    }
    if (auto* the_cast_to_weapon = dynamic_cast<ConcreteWeapon*>(item); the_cast_to_weapon) {
        return "Weapon";
    }

    return "Unknown";
}


class MagicDecorator : public Item {
public:
    MagicDecorator(Item* item, int mod) : item_(item), magic_modifier_(mod) { }

    void setName(const std::string& new_name) override { magic_name_ = new_name; }

    std::string getName() const override {
        std::string namestring = magic_name_;
        namestring += " | ";
        if (magic_modifier_ != 0) {
            namestring += (magic_modifier_ < 0) ? "-" : "+";
        }
        namestring += std::to_string(magic_modifier_) + " ";
        namestring += item_->getName() + " | ";
        namestring += getItemTypeString();
        return namestring;
    }

    std::string getItemTypeString() const {
        return WhatIsItemTypeString(item_);
    }
    int getMagicMod() const { return magic_modifier_; }

protected:
    Item* item_;
    std::string magic_name_;
    int magic_modifier_;
};
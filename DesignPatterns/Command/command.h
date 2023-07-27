#pragma once

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

// Receiver 
class IArmedForce{
public:
    virtual ~IArmedForce() = default;
    virtual void salute() const = 0;
    void fall_back(const std::string &area) const
    {
        std::cout << "Roger that! Protect " << area << '\n';
    }
    void attack_to(const std::string &area) const
    {
        std::cout << "Roger that! Assault to " << area << '\n';
    }
    void end_battle() const
    {
        std::cout << "Run away....\n";
    }
};

class Swordsman : public IArmedForce{
    virtual void salute() const {
        std::cout << "Swordsman: o7\n";
    }
};

class Viking : public IArmedForce{
    virtual void salute() const {
        std::cout << "Vikings: Auh Auh Auh!\n";
    }
};

class Archer : public IArmedForce{
    virtual void salute() const {
        std::cout << "Archer: o7!\n";
    }
};

// Commander
using Army = std::vector<std::shared_ptr<IArmedForce>>;
enum class Order{ ATTACK, DEFEND, ENDBATTLE, SALUTE};

class ICommand {
public:
    virtual ~ICommand() = default;

    virtual void Execute() const = 0;
};

class Commander : public ICommand{
private:
    Order order_;
    Army forces_;

public:
    virtual ~Commander() = default;
    Commander(Order ord, Army frcs) : order_{ ord }, forces_{ frcs } {}

    void Execute() const override
    {
        switch (order_)
        {
            case Order::ATTACK:
            {
                for (const auto& fr : forces_)
                    fr->attack_to("enemy base!");
                break;
            }
            case Order::DEFEND:
            {
                for (const auto& fr : forces_)
                    fr->fall_back("our base!");
                break;
            }
            case Order::ENDBATTLE: 
            {
                for (const auto& fr : forces_)
                    fr->end_battle();
                break;
            }
            case Order::SALUTE:
            {
                for (const auto& fr : forces_)
                    fr->salute();
                break;
            }
            default:
                break;
        }
    }
};

class Invoker
{
private:
    std::unique_ptr<ICommand> invade;
    std::unique_ptr<ICommand> retreat;
    std::unique_ptr<ICommand> end_battle;
    std::unique_ptr<ICommand> salute;

public:
    void SetInvadeCommand(std::unique_ptr<ICommand> command){
        std::swap(retreat, command);
    }
    void SetRetreatCommand(std::unique_ptr<ICommand> command){
        std::swap(retreat, command);
    }
    void SetEndBattleCommand(std::unique_ptr<ICommand> command){
        std::swap(end_battle, command);
    }
    void SetSaluteCommand(std::unique_ptr<ICommand> command) {
        std::swap(salute, command);
    }

    void DoTheWork(){
        if (invade){
            invade->Execute();
        }
        if (salute) {
            salute->Execute();
        }
        if (retreat){
            retreat->Execute();
        }
        if (end_battle){
            end_battle->Execute();
        }
    }
};


// Factory
class ITroopSpawner {
public:
    virtual ~ITroopSpawner() {}
    virtual std::shared_ptr<IArmedForce> spawnTroop() const = 0;
};

class SwordsmanSpawner : public ITroopSpawner {
public:
    std::shared_ptr<IArmedForce> spawnTroop() const override { return std::make_shared<Swordsman>(); }
};

class VikingSpawner : public ITroopSpawner {
public:
    std::shared_ptr<IArmedForce> spawnTroop() const override { return std::make_shared<Viking>(); }
};

class ArcherSpawner : public ITroopSpawner {
public:
    std::shared_ptr<IArmedForce> spawnTroop() const override { return std::make_shared<Archer>(); }
};
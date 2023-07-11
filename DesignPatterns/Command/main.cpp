#include "command.h"
#include <random>
std::mt19937& eng() {
    static std::mt19937 eng{ std::random_device{}() };
    return eng;
}

int main()
{
    SwordsmanSpawner ss;
    VikingsSpawner vs;
    ArcherSpawner as;

    Army army;

    for (std::size_t i{}; i < ((eng()() % 4) + 1); ++i) {
        army.push_back(ss.spawnTroop());
        army.push_back(vs.spawnTroop());
        army.push_back(as.spawnTroop());
    }

    std::shuffle(army.begin(), army.end(), eng());

    auto cm = std::make_unique<Commander>(Order::ATTACK, army);
    cm->Execute();

    //// invoking sets of commands demo
    auto cm2 = std::make_unique<Commander>(Order::SALUTE, army);
    auto cm3 = std::make_unique<Commander>(Order::DEFEND, army);
    auto cm4 = std::make_unique<Commander>(Order::ENDBATTLE, army);

    Invoker invoker;
    invoker.SetInvadeCommand(std::move(cm));
    invoker.SetRetreatCommand(std::move(cm3));
    invoker.SetEndBattleCommand(std::move(cm4));
    invoker.SetSaluteCommand(std::move(cm2));

    invoker.DoTheWork();
}
// WorldState.h
#ifndef WORLD_STATE_H
#define WORLD_STATE_H

#include <string>
#include <map>
#include <vector>

// World state is a map of strings to bools
using WorldState = std::map<std::string, bool>;

// Action structure
struct Action
{
    std::string name;
    WorldState preconditions;
    WorldState effects;
    int cost;

    Action(std::string name, WorldState preconditions, WorldState effects, int cost)
        : name(name), preconditions(preconditions), effects(effects), cost(cost) {}

    bool operator==(const Action &other) const
    {
        return name == other.name;
    }
};

bool PreconditionsMet(const WorldState &preconditions, const WorldState &state);
WorldState ApplyEffects(const WorldState &state, const WorldState &effects);
std::vector<Action> Plan(const WorldState &goal, const WorldState &currentState, const std::vector<Action> &actions, std::vector<Action> currentPlan = {});

#endif // WORLD_STATE_H

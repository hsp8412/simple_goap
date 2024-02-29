#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

// World state is a map of strings to bools
using WorldState = std::map<std::string, bool>;

// Check if a world state meets all the preconditions of an action
bool PreconditionsMet(const WorldState &preconditions, const WorldState &state)
{
    for (const auto &precondition : preconditions)
    {
        if (state.find(precondition.first) == state.end() || state.at(precondition.first) != precondition.second)
        {
            return false;
        }
    }
    return true;
}

// Apply the effects of an action to the current world state
WorldState ApplyEffects(const WorldState &state, const WorldState &effects)
{
    WorldState newState = state;
    for (const auto &effect : effects)
    {
        newState[effect.first] = effect.second;
    }
    return newState;
}

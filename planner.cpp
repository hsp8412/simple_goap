#include <vector>
#include "world_state.h"
#include <iostream>

std::vector<Action> Plan(const WorldState &goal, const WorldState &currentState, const std::vector<Action> &actions, std::vector<Action> currentPlan)
{
    bool goalMet = true;
    for (const auto &g : goal)
    {
        if (currentState.find(g.first) == currentState.end())
        {
            goalMet = false;
            break;
        };
        for (const auto &c : currentState)
        {
            if (g.first == c.first && g.second != c.second)
            {
                goalMet = false;
                break;
            }
        }
    }
    if (goalMet)
    {
        return currentPlan;
    }

    std::vector<Action> possibleActions;

    for (const auto &action : actions)
    {
        if (std::find(currentPlan.begin(), currentPlan.end(), action) != currentPlan.end())
        {
            continue;
        }
        if (PreconditionsMet(action.preconditions, currentState))
        {
            possibleActions.push_back(action);
        }
    }

    std::vector<Action> bestPlan;

    for (const auto &action : possibleActions)
    {
        WorldState nextState = ApplyEffects(currentState, action.effects);
        auto newPlan = currentPlan;
        newPlan.push_back(action);

        auto plan = Plan(goal, nextState, actions, newPlan);
        if (!plan.empty())
        {
            if (bestPlan.empty() || plan.size() < bestPlan.size())
            {
                bestPlan = plan;
            }
        }
    }

    return bestPlan;
}

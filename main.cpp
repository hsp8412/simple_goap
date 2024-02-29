#include <vector>
#include "world_state.h"
#include <iostream>

int main()
{
    // Define actions
    std::vector<Action> actions = {
        Action("Burn Assignment", {{"At Firepit", true}}, {{"Assignment Burn", true}}, 1),
        Action("Get Assignment", {}, {{"Have Assignment", true}}, 1),
        Action("Move to Firepit", {{"Have Assignment", true}}, {{"At Firepit", true}}, 1)};

    // Define the goal
    WorldState goal = {{"Assignment Burn", true}};

    // Initial world state
    WorldState initialState = {};

    // Generate the plan
    auto plan = Plan(goal, initialState, actions);
    std::cout << "Plan:\n";
    for (const auto &action : plan)
    {
        std::cout << action.name << "\n";
    }

    return 0;
}
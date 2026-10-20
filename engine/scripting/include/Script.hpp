#pragma once

#include "Component.hpp"

namespace Elysium {

class Entity;

/**
 * @class Script
 * @brief Base class for scripts attached to entities.
 */
class Script : public Component {
public:
    Entity* entity = nullptr;

    virtual ~Script() = default;

    /**
     * @brief Called once when the script is attached to an entity.
     */
    virtual void OnCreate() {}

    /**
     * @brief Called every simulation frame.
     * @param dt Delta time in seconds.
     */
    virtual void OnUpdate(float dt) { (void)dt; }

    /**
     * @brief Called when the script or entity is destroyed.
     */
    virtual void OnDestroy() {}

    void Update(float dt) override {
        OnUpdate(dt);
    }
};

} // namespace Elysium

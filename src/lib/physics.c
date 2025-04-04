#include "physics.h"

PhysicsObject CreatePhysicsObject(float x, float y, float mass)
{
    PhysicsObject object;
    object.position = (Vector2) {x, y};
    object.velocity = (Vector2) {0.0f, 0.0f};
    object.acceleration = (Vector2) {0.0f, 0.0f};
    object.mass = mass > 0.0f ? mass : 1.0f;

    return object;
}

void UpdatePhysicsObject(PhysicsObject *object, float deltaTime)
{
    object->velocity.x += object->acceleration.x * deltaTime;
    object->velocity.y += object->acceleration.y * deltaTime;
    
    object->position.x += object->velocity.x * deltaTime;
    object->position.y += object->velocity.y * deltaTime;
}
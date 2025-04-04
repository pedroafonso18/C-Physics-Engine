#ifndef PHYSICS_H
#define PHYSICS_H

#include <raylib.h>

typedef struct {
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    float mass;
} PhysicsObject;

PhysicsObject CreatePhysicsObject(float x, float y, float mass);
void UpdatePhysicsObject(PhysicsObject *object, float deltaTime);
#endif
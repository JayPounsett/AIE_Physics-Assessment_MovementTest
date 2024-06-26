#pragma once
#include "PhysicsObject.h"
#include "RigidBody.h"

class Box : public Rigidbody
{
public:
  Box(
    glm::vec2 position,
    glm::vec2 extents,
    glm::vec2 velocity,
    float mass,
    float elasticity,
    glm::vec4 colour)
    : Rigidbody(BOX, position, velocity, mass, elasticity, 0.0f, m_moment)
  {
    m_extents = extents;
    m_colour = colour;
    this->m_orientationRadians = 0.0f;
    m_moment = setMoment(mass, extents.x, extents.y);
  };
  Box(
    glm::vec2 position,
    glm::vec2 extents,
    glm::vec2 velocity,
    float mass,
    float angle,
    float elasticity,
    glm::vec4 colour)
    : Rigidbody(BOX, position, velocity, mass, elasticity, angle, m_moment)
  {
    m_extents = extents;
    m_colour = colour;
    this->setOrientation(angle);
    m_moment = setMoment(mass, extents.x, extents.y);
  };

  ~Box();

  bool checkBoxCorners(
    const Box& box,
    glm::vec2& contact,
    int& numContacts,
    float& pen,
    glm::vec2& edgeNormal);
  virtual void draw();

  void rotate(glm::vec2 vec, float angleDegrees, glm::vec2 origin);

  void drawCueAimLine();

  glm::vec4 getColour() const { return m_colour; }
  glm::vec2 getExtents() const { return m_extents; }
  glm::vec2 getPosition() const { return m_position; }
  // Get the x-axis facing of the box
  glm::vec2 getFacing();

  float getMoment() { return m_moment; }

  float getHeight() { return 2.0f * m_extents.y; }
  float getWidth() { return 2.0f * m_extents.x; }

protected:
  float setMoment(float mass, float x, float y)
  {
    return 1.0f / 12.0f * mass * (2 * x) * (2 * y);
  }

  glm::vec2 rotatePoint(glm::vec2 point, float angle)
  {
    float x = point.x * cos(angle) - point.y * sin(angle);
    float y = point.x * sin(angle) + point.y * cos(angle);
    return glm::vec2(x, y);
  }

protected:
  glm::vec2 m_extents; // the half-edge lengths
  glm::vec4 m_colour;
    
  // The corners of the box
  glm::vec2 m_topLeft = glm::vec2(0);
  glm::vec2 m_bottomLeft = glm::vec2(0);
  glm::vec2 m_topRight = glm::vec2(0);
  glm::vec2 m_bottomRight = glm::vec2(0);
};

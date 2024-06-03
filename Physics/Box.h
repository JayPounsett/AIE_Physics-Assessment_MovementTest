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

  // void fixedUpdate(glm::vec2 gravity, float timeStep);
  bool checkBoxCorners(
    const Box& box,
    glm::vec2& contact,
    int& numContacts,
    float& pen,
    glm::vec2& edgeNormal);
  virtual void draw();


#pragma region Create Matrix3
  glm::mat3 createTranslationMatrix(glm::vec2 position)
  {
    glm::mat3 translationMatrix = glm::mat3(
      1.0f, 0.0f, position.x, 0.0f, 1.0f, position.y, 0.0f, 0.0f, 1.0f);

    return translationMatrix;
  }

  glm::mat3 createRotationMatrix(float angleRadians)
  {
    glm::mat3 rotationMatrix = glm::mat3(
      cos(angleRadians),
      -sin(angleRadians),
      0.0f,
      sin(angleRadians),
      cos(angleRadians),
      0.0f,
      0.0f,
      0.0f,
      1.0f);

    return rotationMatrix;
  }

  glm::mat3 createScaleMatrix(float xScale, float yScale)
  {
    glm::mat3 scaleMatrix =
      glm::mat3(xScale, 0.0f, 0.0f, 0.0f, yScale, 0.0f, 0.0f, 0.0f, 1.0f);

    return scaleMatrix;
  }
#pragma endregion Create Matrix3

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

protected:
  glm::vec2 m_extents; // the half-edge lengths
  glm::vec4 m_colour;
};

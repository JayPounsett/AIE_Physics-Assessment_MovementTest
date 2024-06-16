#include "PoolTableGame.h"

#include <Input.h>

PoolTableGame::~PoolTableGame() {}

void PoolTableGame::update(float deltaTime, aie::Input* input)
{
  if (m_cueStick == nullptr || m_cueBall == nullptr) return;

  GameInput(deltaTime, input, m_cueStick, m_cueBall);
}

void PoolTableGame::draw() { m_cueStick->draw(); }

void PoolTableGame::GameInput(
  float deltaTime, aie::Input* input, Box* box, Sphere* sphere)
{
  // Get the current position of the box and sphere
  glm::vec2 boxPosition = box->getPosition();
  glm::vec2 spherePosition = sphere->getPosition();

  // Calculate the direction from box to sphere
  glm::vec2 direction = glm::normalize(spherePosition - boxPosition);

  //// Define the direction of the side of the box that will face the sphere
  //glm::vec2 sideDirection = glm::vec2(-1, 0);

  //float angle = glm::orientedAngle(sideDirection, direction);

  //// Update the orientation of the box based on the calculated angle
  //box->setOrientation(glm::degrees(angle));

  // Calculate the perpendicular direction for strafing
  glm::vec2 rotationDirection = glm::vec2(-direction.y, direction.x);

  // Calculate the up vector for the lookAt matrix
  glm::vec2 up = glm::vec2(0, 1);

  // Calculate the lookAt matrix
  glm::mat4 lookAtMatrix = glm::lookAt(
    glm::vec3(boxPosition.x, boxPosition.y, 0),
    glm::vec3(spherePosition.x, spherePosition.y, 0),
    glm::vec3(0, 0, 1));

  // Extract the rotation matrix from the lookAt matrix
  m_cueStickRotationMatrix = glm::mat3(lookAtMatrix);

  // Calculate the new orientation based on the rotation matrix
  float newOrientation =
    glm::degrees(atan2(m_cueStickRotationMatrix[1][0], m_cueStickRotationMatrix[0][0]));

  // Update the orientation of the box
  box->setOrientation(newOrientation + 90.0f);

  // Define movement speed for strafing
  float strafeSpeed = 100.0f * deltaTime;

  // Move left when pressing A
  if (input->isKeyDown(aie::INPUT_KEY_A))
  {
    box->setPosition(box->getPosition() - rotationDirection * strafeSpeed);
  }

  // Move right when pressing D
  if (input->isKeyDown(aie::INPUT_KEY_D))
  {
    box->setPosition(box->getPosition() + rotationDirection * strafeSpeed);
  }

  // Move toward sphere when pressing W
  if (input->isKeyDown(aie::INPUT_KEY_W))
  {
    box->setPosition(box->getPosition() + direction * strafeSpeed);
  }

  // Move away from sphere when pressing S
  if (input->isKeyDown(aie::INPUT_KEY_S))
  {
    box->setPosition(box->getPosition() - direction * strafeSpeed);
  }
}

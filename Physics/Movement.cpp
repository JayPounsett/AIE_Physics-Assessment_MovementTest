#include "Movement.h"

#include <Input.h>

MoveBox::~MoveBox() {}

void MoveBox::update(float deltaTime, aie::Input* input)
{
  if (m_box == nullptr) return;

  moveBox(deltaTime, input, m_box);
}

void MoveBox::draw()
{ m_box->draw(); }

void MoveBox::moveBox(float deltaTime, aie::Input* input, Box* box)
{
  // Move up the screen
  if (input->isKeyDown(aie::INPUT_KEY_W))
  {
    box->setPosition(
      glm::vec2(box->getPosition().x, box->getPosition().y + 1.0f));
  }

  // Move down the Screen
  if (input->isKeyDown(aie::INPUT_KEY_S))
  {
    box->setPosition(
      glm::vec2(box->getPosition().x, box->getPosition().y - 1.0f));
  }

  // Move left on the screen
  if (input->isKeyDown(aie::INPUT_KEY_A))
  {
    box->setPosition(
      glm::vec2(box->getPosition().x - 1.0f, box->getPosition().y));
  }

  // Move right on the screen
  if (input->isKeyDown(aie::INPUT_KEY_D))
  {
    box->setPosition(
      glm::vec2(box->getPosition().x + 1.0f, box->getPosition().y));
  }

  // Turn left
  if (input->isKeyDown(aie::INPUT_KEY_Q))
  {
    box->setOrientation(glm::degrees(box->getOrientationRadians()) - deltaTime);
  }

  // Turn right
  if (input->isKeyDown(aie::INPUT_KEY_E))
  {
    box->setOrientation(glm::degrees(box->getOrientationRadians()) + deltaTime);
  }
}

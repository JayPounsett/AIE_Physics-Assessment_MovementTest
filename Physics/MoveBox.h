#pragma once

#include "Box.h"

#include <Input.h>

class MoveBox
{
public:
  MoveBox(Box* box) { m_box = box; }
  ~MoveBox();

  void update(float deltaTime, aie::Input* input);
  void draw();

protected:
  /// <summary>
  /// Move a rigidbody object up/down/left/right and rotate left/right.
  /// </summary>
  /// <param name="deltaTime"> Time since last frame.</param>
  /// <param name="input"> Input object.</param>
  /// <param name="obj"> Rigidbody object to move.</param>
  void moveBox(float deltaTime, aie::Input* input, Box* box);

protected:
  glm::mat3 m_boxMatrix = glm::mat3(0.0f);
  Box* m_box;
};

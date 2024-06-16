#pragma once

#include "Box.h"
#include "Sphere.h"

#include <Input.h>

class PoolTableGame
{
public:
  PoolTableGame(Box* box, Sphere* sphere) { m_cueStick = box; m_cueBall = sphere; }
  ~PoolTableGame();

  void update(float deltaTime, aie::Input* input);
  void draw();

protected:
  /// <summary>
  /// Move a rigidbody object up/down/left/right and rotate left/right.
  /// </summary>
  /// <param name="deltaTime"> Time since last frame.</param>
  /// <param name="input"> Input object.</param>
  /// <param name="obj"> Rigidbody object to move.</param>
  void GameInput(float deltaTime, aie::Input* input, Box* box, Sphere* sphere);

protected:
  glm::mat3 m_cueStickRotationMatrix = glm::mat3(1.0f);

  Box* m_cueStick;
  Sphere* m_cueBall;
  
};

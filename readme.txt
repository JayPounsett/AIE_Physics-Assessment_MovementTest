Copy of Assessment Project to create a movement system without thinking about the game simulation.

## Keyboard Controls
W: Toward sphere
S: Away from sphere
A: Rotate counter-clockwise
D: Rotate clockwise

Currently the box rotates around the sphere as well as moves toward and away from it yet does not yet face the sphere. The movement is correct though when it rotates around the sphere as it always moves towards the sphere with W (or away with S).

## Code Notes
- moveBoxTest() is started in PhysicsApp::Startup()
- All movement functionality is within MoveBox::moveBox()

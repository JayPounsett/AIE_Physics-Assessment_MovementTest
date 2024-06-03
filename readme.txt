Copy of Assessment Project to create a movement system without thinking about the game simulation.

## Keyboard Controls
W: Up
S: Down
A: Left
D: Right
Q: Turn Left
E: Turn Right

Currently the box only moves up/down/left/right while turn left/right is not yet functioning.

## Code Notes
- moveBoxTest() is started in PhysicsApp::Startup()
- All movement functionality is within MoveBox.h
- Box::draw() creates a rotation matrix and uses that to alter the box's points as it is drawn, hoping to have it rotate.

🚀 Project Overview

This robot is designed for mobile manipulation tasks. By combining a 6-axis arm with a holonomic base, the system can reach targets in 3D space while simultaneously repositioning itself in any direction (omnidirectional movement).
Key Features:

    6-DOF Articulation: High dexterity for complex grasping and positioning.

    Mecanum Drive: 4-wheel omnidirectional movement for precise navigation in tight spaces.

    Inverse Kinematics (IK): Algorithmic control to move the gripper to specific
    (x,y,z)

    coordinates.

    PID Control: Closed-loop feedback for smooth, jitter-free motor transitions.

    Digital Twin: Fully modeled and tested in CoppeliaSim prior to hardware deployment.

🛠 Tech Stack

    Hardware: Arduino (Mega/Uno), MG996R/SG90 Servos, L298N/L293D Motor Drivers, Mecanum Wheels.

    Simulation: CoppeliaSim (V-REP).

    Languages: C++ (Arduino Sketch), Lua (CoppeliaSim scripting).

    Concepts: Inverse Kinematics, PID Control, PWM Signal Processing.

📐 System Architecture
1. Kinematics & Control

The arm uses Inverse Kinematics to calculate the required joint angles for a desired end-effector position.
θ1​,θ2​,...θ6​=f−1(x,y,z,roll,pitch,yaw)
2. The Mobile Base

The 4-wheel Mecanum setup allows for translation and rotation simultaneously.

    Forward/Backward: All wheels rotate same direction.

    Strafe (Lateral): Wheels rotate in opposing "X" patterns.

3. Simulation (CoppeliaSim)

Before physical assembly, the robot was stress-tested in a virtual environment to:

    Verify the workspace reach.

    Tune PID constants without risking hardware damage.

    Validate the IK solver logic.

This project presents a mobile manipulation robot designed to perform complex 3D tasks in dynamic environments. By integrating a 6-DOF robotic arm with a Mecanum-wheel holonomic base, the system achieves high dexterity and omnidirectional mobility, enabling it to reach targets while maneuvering seamlessly in tight spaces.

![WhatsApp Image 2024-08-10 at 17 37 55_4350a684](https://github.com/user-attachments/assets/0edd24e4-c1b2-4592-b722-b233598e7695)
![429606107_386938913949386_1463461569626428514_n](https://github.com/user-attachments/assets/ba5d485a-197a-4cc6-b72a-774cfcda9d8a)
![WhatsApp Image 2024-08-10 at 17 37 42_e13a78ed](https://github.com/user-attachments/assets/17fa35be-03e4-4e28-ba89-d86e4b89e9fb)
![WhatsApp Image 2024-08-10 at 17 37 41_aacf836a](https://github.com/user-attachments/assets/6e474fe2-f1a0-4f4f-b8db-66bdf4f329f1)


🌟 Key Features

6-DOF Robotic Arm: Provides high dexterity for complex grasping, precise positioning, and manipulation tasks in 3D space.
Mecanum Drive Base: 4-wheel omnidirectional movement allows translation and rotation simultaneously for precise navigation.
Inverse Kinematics (IK): Algorithmic control computes joint angles to move the gripper to desired coordinates: (x, y, z, roll, pitch, yaw).
PID Control: Closed-loop feedback ensures smooth, jitter-free motion of motors and servos.
Digital Twin Simulation: Full system modeled in CoppeliaSim (V-REP) for testing, tuning, and validation before physical deployment.

🛠 Tech Stack
Hardware: Arduino (Mega/Uno), MG996R/SG90 Servos, L298N/L293D Motor Drivers, Mecanum Wheels
Simulation: CoppeliaSim (V-REP) for virtual prototyping, workspace analysis, and PID tuning
Programming Languages: C++ (Arduino Sketches),Lua (CoppeliaSim scripting)
Concepts Implemented: Inverse Kinematics, PID Control, PWM Signal Processing, Mecanum Wheel Kinematics

📐 System Architecture
1. Kinematics & Control:
The arm uses Inverse Kinematics to calculate joint angles for a desired end-effector position: (x,y,z,roll,pitch,yaw)

3. Mobile Base: 
The 4-wheel Mecanum setup enables omnidirectional movement:
Forward/Backward: All wheels rotate in the same direction.
Strafe (Lateral): Wheels rotate in opposing "X" patterns.
Rotation (Yaw): Wheels rotate to allow rotation in place.

4. Simulation (CoppeliaSim)
Before assembling the physical robot, the system was tested in simulation to:
Verify workspace reach and obstacle handling
Tune PID constants safely
Validate IK solver accuracy

📁 Repository Structure
├── Arduino/           # Arduino sketches for arm and base control
├── CoppeliaSim/       # CoppeliaSim scenes and Lua scripts
├── Docs/              # Documentation, schematics, and diagrams
├── Config/            # PID constants, motor parameters, and calibration files
├── README.md
└── LICENSE

🚀 Getting Started
Requirements:
Arduino IDE
CoppeliaSim (V-REP)
MG996R/SG90 Servos
L298N/L293D Motor Drivers

Mecanum Wheels

# Robot-smart-car-controlled-by-phone-application-via-bluetooth-wifi

The Project Description:
A robot car that is powered by 2 rear motors and a castor wheel in the front. It is controlled via a phone application, designed on appinventor, that simulates a 
joystick. It sends serial data of the coordinates joystick to the HC-05 module which determines the voltage and direction of each DC motor. The speed and direction of the motor
is controlled by the L298N motor driver. All components are attached onto the brickboard which acts as the chassis for the car. The car also includes a collision warning system 
that sounds a buzzer if the front of car is less than 5cm away from any obsticle. This is achieved with the help of a ultrasonic sensor. It is powered by a 12V,2A AC to DC.

Experience:
This was a fun starter project to understand and build on my arduino knowledge. Understood how the components communicate with each other and the familiarised myself with 
arduino IDE. Challenging part of the project was to make an app that communicates with the HC-05 and figuring out the relationship between joystick position and motor voltage.

What could be improved:
Integrate a collision avoidance system which acts on the warning system that prohibits the car from moving foward and only allows reverse mode. This can be implemented by just
changing the code to switch from front() state to reverse() state whenver the distance is less than 5cm. The top half of the joystick also has to be deactivated. Secondly, we can replace the castor wheel in the front with 2 more wheels with steering enabled using a servo. This is better than rear wheel differential to steer the car since it has 
better handling.

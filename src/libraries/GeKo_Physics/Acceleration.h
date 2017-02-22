#pragma once

///A class to add acceleration to an  object.
/** The speed is added each frame to the object untill it reaches a maximum speed, so that it seems the objects gets faster gradually.
*/
class Acceleration{
protected:
	double m_acceleration;
	double m_speed; 		 
	double maxSpeed;    
	
public:
	Acceleration();
	///Every acceleration needs a value and a maximum
	Acceleration(double accel, double max);
	~Acceleration();

	void setAcceleration(double newAccel);
	double getAcceleration();
	
	///The accelaration will be used to increase the speed
	/**If the maximum is not reached the m_speed will be accelerated with m_acceleration*/
	void accelerate();

	void setSpeed(double speed);
	double getSpeed();
};
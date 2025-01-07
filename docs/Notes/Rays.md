# Ray definition
Our ray is defined something like this:

P(t) = A + (t * d) 

Here P is a 3D position along a line in 3D. A is the vector's origin, and d is the directiion.

P(t) moves along the line for every t given. For negetive t it goes backwards as it should...

We have a function named ray::at(double t) it does the exact thing. Return's it's position at t (time?)

# Sending Ray into the scene
What ray tracer basically does it this only. Sends thousands of rays into the scene and changes the colour reacting to the environment. We just draw it out....

Calculate ray from the eye through the pixel
Determine which objects the ray intersects
Compute a color for the closest intersection point.

### We keep the camera(Eye) at the center at (0,0,0).
In our co-ordinate system 
1. Pos y-axis goes up. 
2. Pos x-axis goes right.
3. Pos z-axis goes in the opposite of viewing direction. In simple words the negetive z-axis goes in the viewing direction...
##### This type of co-ordinate is called right handed co-ordinates.



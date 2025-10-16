#version 330

in	vec2	a_Position;	// attribute variable: position vector
in	vec3	a_Color;	// attribute variable: color vector

out	vec4	v_Color;	// varying variable for passing color to fragment shader

uniform	mat4	u_Modelview;	// uniform variable for passing modelview  matrix
uniform	mat4	u_Projection;	// uniform variable for passing projection matrix
uniform	float	u_Theta;	// Theta parameter
uniform	int	u_Twist;	// Twist flag

void main() 
{
	float d   = (u_Twist != 0) ? length(a_Position) : 1.0;
    float ang = u_Theta * d;
    float s = sin(ang), c = cos(ang);
    vec2 p = vec2(c*a_Position.x - s*a_Position.y,
                  s*a_Position.x + c*a_Position.y);

    gl_Position = u_Projection * u_Modelview * vec4(p, 0.0, 1.0);
    v_Color = vec4(a_Color, 1.0); 
}
